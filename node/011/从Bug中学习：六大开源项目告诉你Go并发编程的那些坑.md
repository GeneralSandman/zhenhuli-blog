
# 从bug中学习：六大开源项目告诉你go并发编程的那些坑

> 并发编程中，go不仅仅支持传统的通过共享内存的方式来通信，更推崇通过channel来传递消息，这种新的并发编程模型会出现不同于以往的bug。从bug中学习，《Understanding Real-World Concurrency Bugs in Go》这篇paper在分析了六大开源项目并发相关的bug之后，为我们总结了go并发编程中常见的坑。别往坑里跳，编程更美妙。

在go中，创建goroutine非常简单，在函数调用前加go关键字，这个函数的调用就在一个单独的goroutine中执行了；go支持匿名函数，让创建goroutine的操作更加简洁。另外，在并发编程模型上，go不仅仅支持传统的通过共享内存的方式来通信，更推崇通过channel来传递消息：

> Do not communicate by sharing memory; instead, share memory by communicating.

这种新的并发编程模型会带来新类型的bug，从bug中学习，《Understanding Real-World Concurrency Bugs in Go》这篇paper在Docker、Kubernetes、etcd、gRPC、CockroachDB、BoltDB六大开源项目的commit log中搜索"race"、“deadlock”、“synchronization”、“concurrency”、“lock”、“mutex”、“atomic”、“compete”、“context”、“once”、"goroutine leak"等关键字，找出了这六大项目中并发相关的bug，然后归类这些bug，总结出了go并发编程中常见的一些坑。通过学习这些坑，可以让我们在以后的项目里防范类似的错误，或者遇到类似问题的时候可以帮助指导快速定位排查。

## 1. unbuffered channel由于receiver退出导致sender侧block

如下面一个bug的例子：

```go
func finishReq(timeout time.Duration) ob {
    ch := make(chan ob)
    go func() {
        result := fn()
        ch <- result // block
    }()
    select {
    case result = <-ch:
        return result
    case <-time.After(timeout):
        return nil
    }
}
```

本意是想调用fn()时加上超时的功能，如果fn()在超时时间没有返回，则返回nil。但是当超时发生的时候，针对代码中第二行创建的ch来说，由于已经没有receiver了，第5行将会被block住，导致这个goroutine永远不会退出。

> If the capacity is zero or absent, the channel is unbuffered and communication succeeds only when both a sender and receiver are ready. Otherwise, the channel is buffered and communication succeeds without blocking if the buffer is not full (sends) or not empty (receives).

这个bug的修复方式也是非常的简单，把unbuffered channel修改成buffered channel。

```go


func finishReq(timeout time.Duration) ob {
    ch := make(chan ob, 1)
    go func() {
        result := fn()
        ch <- result // block
    }()
    select {
    case result = <-ch:
        return result
    case <-time.After(timeout):
        return nil
    }
}

```

> 思考：在上面的例子中，虽然这样不会block了，但是channel一直没有被关闭，channel保持不关闭是否会导致资源的泄漏呢？

## 2. WaitGroup误用导致阻塞

下面是一个WaitGroup误用导致阻塞的一个bug的例子：

https://github.com/moby/moby/pull/25384

```go

var group sync.WaitGroup
group.Add(len(pm.plugins))
for _, p := range pm.plugins {
    go func(p *plugin) {
        defer group.Done()
    }(p)
    group.Wait()
}
```

当len(pm.plugins)大于等于2时，第7行将会被卡住，因为这个时候只启动了一个异步的goroutine，group.Done()只会被调用一次，group.Wait()将会永久阻塞。修复如下：

```go

var group sync.WaitGroup
group.Add(len(pm.plugins))
for _, p := range pm.plugins {
    go func(p *plugin) {
        defer group.Done()
    }(p)
}
group.Wait()

```

## 3. context误用导致资源泄漏
如下面的代码所示：
```go

hctx, hcancel := context.WithCancel(ctx)
if timeout > 0 {
    hctx, hcancel = context.WithTimeout(ctx, timeout)
}
```
第一行context.WithCancel(ctx)有可能会创建一个goroutine，来等待ctx是否Done，如果parent的ctx.Done()的话，cancel掉child的context。也就是说hcancel绑定了一定的资源，不能直接覆盖。

> Canceling this context releases resources associated with it, so code should call cancel as soon as the operations running in this Context complete.

这个bug的修复方式是：
```go
var hctx context.Context
var hcancel context.CancelFunc
if timeout > 0 {
    hctx, hcancel = context.WithTimeout(ctx, timeout)
} else {
    hctx, hcancel = context.WithCancel(ctx)
}
```

或者

```go
hctx, hcancel := context.WithCancel(ctx)
if timeout > 0 {
    hcancel.Cancel()
    hctx, hcancel = context.WithTimeout(ctx, timeout)
}
```

## 4. 多个goroutine同时读写共享变量导致的bug

如下面的例子：

```go
for i := 17; i <= 21; i++ { // write
    go func() { /* Create a new goroutine */
        apiVersion := fmt.Sprintf("v1.%d", i) // read
    }()
}
```

第二行中的匿名函数形成了一个闭包(closures)，在闭包内部可以访问定义在外面的变量，如上面的例子中，第1行在写i这个变量，在第3行在读i这个变量。这里的关键的问题是对同一个变量的读写是在两个goroutine里面同时进行的，因此是不安全的。

> Function literals are closures: they may refer to variables defined in a surrounding function. Those variables are then shared between the surrounding function and the function literal, and they survive as long as they are accessible.

可以修改成：
```go

for i := 17; i <= 21; i++ { // write
    go func(i int) { /* Create a new goroutine */
        apiVersion := fmt.Sprintf("v1.%d", i) // read
    }(i)
}
```

通过passed by value的方式规避了并发读写的问题。

## 5. channel被关闭多次引发的bug

https://github.com/moby/moby/pull/24007/files

```go

select {
case <-c.closed:
default:
    close(c.closed)
}
```

上面这块代码可能会被多个goroutine同时执行，这段代码的逻辑是，case这个分支判断closed这个channel是否被关闭了，如果被关闭的话，就什么都不做；如果closed没有被关闭的话，就执行default分支关闭这个channel，多个goroutine并发执行的时候，有可能会导致closed这个channel被关闭多次。

> For a channel c, the built-in function close(c) records that no more values will be sent on the channel. It is an error if c is a receive-only channel. Sending to or closing a closed channel causes a run-time panic.

这个bug的修复方式是：

```go

Once.Do(func() {
    close(c.closed)
})

```

把整个select语句块换成Once.Do，保证channel只关闭一次。

## 6. timer误用产生的bug

如下面的例子：

```go

timer := time.NewTimer(0)
if dur > 0 {
    timer = time.NewTimer(dur)
}
select {
case <-timer.C:
case <-ctx.Done():
    return nil
}
```

原意是想dur大于0的时候，设置timer超时时间，但是timer := time.NewTimer(0)导致timer.C立即触发。修复后：

```go

var timeout <-chan time.Time
if dur > 0 {
    timeout = time.NewTimer(dur).C
}
select {
case <-timeout:
case <-ctx.Done():
    return nil
}

```

> A nil channel is never ready for communication.

上面的代码中第一个case分支timeout有可能是个nil的channel，select在nil的channel上，这个分支不会被触发，因此不会有问题。

## 7.读写锁误用引发的bug

go语言中的RWMutex，write lock有更高的优先级：

> If a goroutine holds a RWMutex for reading and another goroutine might call Lock, no goroutine should expect to be able to acquire a read lock until the initial read lock is released. In particular, this prohibits recursive read locking. This is to ensure that the lock eventually becomes available; a blocked Lock call excludes new readers from acquiring the lock.

如果一个goroutine拿到了一个read lock，然后另外一个goroutine调用了Lock，第一个goroutine再调用read lock的时候会死锁，应予以避免。

## 参考资料

https://songlh.github.io/paper/go-study.pdf

https://golang.org/ref/spec

https://golang.org/doc/effective_go.html

https://golang.org/pkg/


