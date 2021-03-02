# 使用go协程+Channel，让你的代码飞起来

> 传统的串行代码执行，逻辑比较简单，当数据量比较大时，执行效率低下，既然我们使用go，那就利用go相对与其他语言的优势，轻量化的协程以及channel，接下来让我们使用go协程+chan，让我们的代码速度来个大的飞跃吧～
背景：  

最近做了一个需求，是产品小姐姐提的对于流失用户的召回，精简一下流程，首先从表1中取出符合多少天未登陆条件的用户uid，然后利用这个用户uid在表2中进行比较(如果用户曾经被召回过，会在表2中留下一条记录，之后就不再召回)，如果表2中有该用户的记录，就不做任何操作，如果没有，则触发用户召回的服务。当然实际业务比这个要复杂，但只从这个精简的业务中，也能找到很多优化我们代码的地方，从而提高效率。

## 第一次尝试demo：

 在接到这个需求的时候，心情非常开心，这不就是我sql boy发挥作用的时候了吗？于是，很快我就撸出了代码。大致的demo如下(实际业务中不要写魔法数字)

```
var uidTargetList []int
var uidList []int
var id int
for {
    // 每次从表1中取出100个用户，这里id用户遍历，每次取出数据后，返回最后一个用户记录对应的id，然后使用这个id作为读表的比较条件，防止取出重复用户
    if uidList, id, err := lastLoginTimeStore.GetUnloginUserByPage(id,
        100, startTime, endTime); err != nil {
        rlog.Error("get unlogin user by page err", rlog.Err(err))
    }
    if len(uidList) == 0 {
        break
    }

    for index:= range uidList {
        var hasSent bool
        // 判断用户是否被召回过，如果没有，则加入uidTargetList，以便后续触发召回服务
        if hasSent, err := callbackStore.HasSent(uidList[index]); err != nil {
            rlog.Error("get user record error", rlog.Int("uid", uidList[index]), rlog.Err(err))
        }
        if !hasSent {
            uidTargetList = append(uidTargetList, uidList[index])
        }
    }
}

```

很快我就写好了代码，然后我就和产品说，我写好了，服务可以跑了，当天产品就要我先灰度发送，我就发了16w用户，正当我服务跑起来准备刷刷km时，我发现这个速度也太慢了，大概每分钟居然只能处理600个用户，照着这个速度，还不得发到明天，产品可能要把我打死，于是我马上终止了服务，马上进行优化。


## 第一次优化：

 马上我就仔细分析这个服务的瓶颈在哪，这个服务中有2次与数据库的交互，这种操作一般就是效率低的缘由。这里的第一次io操作从表1中取出用户数据，每次取出100条记录，如果增加每次取出的数据，可能会带来超时的风险，同时这样的效率提升也比较小，没有量级的提升，很明显，这个io操作不是我优化的主要目标。于是我将目标放到了第二个io操作，每次只能比较一个用户，这样的效率比较低，所以，我应该优化这个地方，如果我能和第一次io操作一样，能够每次比较100个用户，这样的提升就是量级了，想到这里，我瞬间又重新寻回了新手程序员的蜜汁自信。

 那怎样才能一下比较很多个用户数据，马上，我就想起了可以使用协程啊，有一个用户的数据，就go一个协程去比较，这样的效率不就得到了极大的提升，然后我有一次撸起了袖子，又开始干了。这次代码的demo感觉就比第一版高端了许多。主要是利用 uidChan 和 uidTargetChan 在多协程中传递数据，uidChan传递从表1中查询出的数据，然后在表2中比较，如果符合条件，则将其存入uidTargetChan，最后再利用uidTargetList这个切片，存放所有符合条件的用户uid。

```

// uidHandler 创建一个结构体，包括一个等待队列，然后uidChan 用于在多个协程中传递用户uid
type uidHandler struct {
    wg sync.WaitGroup
    uidChan chan int
}
// uidTargetHandler 同样的这个结构体包括一个等待队列，然后uidTargetChan 用于在多个协程中传递符合条件的用户uid
type uidTargetHandler struct {
    wg sync.WaitGroup
    uidTargetChan chan int
}

func test1()  {
    uh := uidHandler{
        wg:      sync.WaitGroup{},
        uidChan: make(chan int, 100),
    }
    uth := uidTargetHandler{
        wg:            sync.WaitGroup{},
        uidTargetChan: make(chan int, 100),
    }
    // 利用协程启动获取targetUid的服务
    go func() {
        getTargetUid(uh, uth)
    }()

  // 记录下这些targetUid，uidTargetList就是最后保存所有符合条件的uid
    var uidTargetList []int
    go func() {
        RecordTargetUid(uth, &uidTargetList)
    }()

    var uidList []int
    var id int
    for {
        // 每次从表1中取出100个用户，这里id用户遍历，每次取出数据后，返回最后一个用户记录对应的id，然后使用这个id作为读表的比较条件，防止取出重复用户
        if uidList, id, err = lastLoginTimeStore.GetUnloginUserByPage(id,
            100, startTime, endTime); err != nil {
            rlog.Error("get unlogin user by page err", rlog.Err(err))
        }
        if len(uidList) == 0 {
            break
        }
    // 将取出的uid直接放入uh.uidChan
        for index:= range uidList {
            uh.uidChan <- uidList[index]
            uh.wg.Add(1)
        }
    }
    uh.wg.Wait()
    uth.wg.Wait()
  // 当走到这一步时，所有的目标用户的uid全部保存在 uidTargetList 中了
}
      然后我们来看看getTargetUid 和 RecordTargetUid 的代码

// getTargetUid 获取目标uid，即可以发送通知的用户
func getTargetUid(uh uidHandler, uth uidTargetHandler)  {
    for {
        uid := <- uh.uidChan
        uh.wg.Done()
    // 对于用户的uid，直接并发去比较，如果符合条件，就放入uth.uidTargetChan 
        go func(userUid int) {
            var hasSent bool
            var err error
            if hasSent, err = callbackStore.HasSent(userUid); err != nil {
                rlog.Error("get user record error", rlog.Int("uid", userUid), rlog.Err(err))
            }
            if !hasSent {
                uth.uidTargetChan <- userUid
                uth.wg.Add(1)
            }
        }(uid)
    }
}

// RecordTargetUid 记录下可以发送用户的uid，实际业务中应该是直接利用这些uid去启动后续服务
func RecordTargetUid(uth uidTargetHandler, uidTargetList *[]int)  {
    for {
        uid := <- uth.uidTargetChan
        *uidTargetList = append(*uidTargetList, uid)
        uth.wg.Done()
    }
}

```

至此，我就能将所有符合条件的用户uid放在uidTargetList。然后我想着，这样性能就有了量的提升，产品小姐姐待会要夸我真快，真给力。然后我就重启了服务。但。。。，猝不及防的事情又发生了，报了这个“use of closed network connection”错误，经过分析，可能是我协程开了太多了，一下子并发了太多协程去和数据库交互，然后导致出错，进而连接被关闭，最终报了这个错。于是，想着能不能不要并发那么多协程，对同时跑的协程数量进行一个限制。所以又想到了线程池，可以仿造这个概念弄个协程池，但是谷歌了一下，线程池主要就是节省线程的创建和销毁的时间，但是对于协程而言，它的创建和销毁本来就消耗不大，go的协程本来就是非常轻量的，go开发中一般也不建议使用线程池。然后我又陷入了深思，代码好难，人生也好难。


## 第二次优化

自己的脑瓜不够转了，只能去求助外援。然后我只能去请教了dayo大哥，然后dayo传授了我一个江湖典藏小诀窍，专治这个毛病。即利用for循环，只开启固定的协程去处理这些用户uid，在服务器可以承载的范围，这样就不会有特别多的协程同时与数据库交互了。利用这个诀窍，我对 getTargetUid 函数进行了小小的修改，就解决了这个问题，getTargetUid修改后的代码如下：

```

// getTargetUid 获取目标uid，即可以发送通知的用户
func getTargetUid(uh uidHandler, uth uidTargetHandler)  {
  // 只并发100个协程，然后这些协程循环去从chan中读取并进行相应的处理
    for i := 0; i < 100; i++ {
        go func() {
            for {
                uid := <- uh.uidChan
                uh.wg.Done()
                var hasSent bool
                var err error
                if hasSent, err = callbackStore.HasSent(uid); err != nil {
                    rlog.Error("get user record error", rlog.Int("uid", uid), rlog.Err(err))
                }
                if !hasSent {
                    uth.uidTargetChan <- uid
                    uth.wg.Add(1)
                }
            }
        }()
    }
}

```

这次，服务又跑起来了，大概每分钟8000个用户，速度大大提升，产品小姐姐知道了我的壮举后，对我赞不绝口，菜鸡程序员的快乐又有了，这就是我利用go协程提升了服务的效率，总的来说，go的chan非常好用，很方便在多协程间传递数据，chan+协程简直就是利器，还在用线程池的java同学听到了都羡慕哭了。


## 结语：

 使用协程+channel只是众多优化方式的一种，在很多情况下，这样的优化仍是不够的，比如你的表中用户记录一共有2亿条，这样依次遍历效率仍然太低了，可以将用户数据分段，比如每100万个数据分为一段，每一段go一个协程去处理，这样读取的效率也有了极大的提升，还可以增加多台服务器等等，这些都可以提升速度，但这些就不是本文的重点啦，大家可以自己试着用多协程+chan去优化一下自己的代码，提升代码的运行速度吧～