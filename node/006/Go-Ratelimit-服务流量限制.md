# Ratelimit 服务流量限制

计算机程序可依据其瓶颈分为磁盘IO瓶颈型，CPU计算瓶颈型，网络带宽瓶颈型，分布式场景下有时候也会外部系统而导致自身瓶颈。


Web系统打交道最多的是网络，无论是接收，解析用户请求，访问存储，还是把响应数据返回给用户，都是要走网络的。在没有epoll/kqueue之类的系统提供的IO多路复用接口之前，多个核心的现代计算机最头痛的是C10k问题，C10k问题会导致计算机没有办法充分利用CPU来处理更多的用户连接，进而没有办法通过优化程序提升CPU利用率来处理更多的请求。


自从Linux实现了epoll，FreeBSD实现了kqueue，这个问题基本解决了，我们可以借助内核提供的API轻松解决当年的C10k问题，也就是说如今如果你的程序主要是和网络打交道，那么瓶颈一定在用户程序而不在操作系统内核。


随着时代的发展，编程语言对这些系统调用又进一步进行了封装，如今做应用层开发，几乎不会在程序中看到epoll之类的字眼，大多数时候我们就只要聚焦在业务逻辑上就好。Go 的 net 库针对不同平台封装了不同的syscall API，http库又是构建在net库之上，所以在Go语言中我们可以借助标准库，很轻松地写出高性能的http服务，下面是一个简单的hello world服务的代码：


```go
package main

import (
    "io"
    "log"
    "net/http"
)

func sayhello(wr http.ResponseWriter, r *http.Request) {
    wr.WriteHeader(200)
    io.WriteString(wr, "hello world")
}

func main() {
    http.HandleFunc("/", sayhello)
    err := http.ListenAndServe(":9090", nil)
    if err != nil {
        log.Fatal("ListenAndServe:", err)
    }
}
```

我们需要衡量一下这个Web服务的吞吐量，再具体一些，就是接口的QPS。借助wrk，在家用电脑 Macbook Pro上对这个 hello world 服务进行基准测试，Mac的硬件情况如下：

```shell

CPU: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz
Core: 2
Threads: 4

Graphics/Displays:
      Chipset Model: Intel Iris Graphics 6100
          Resolution: 2560 x 1600 Retina
    Memory Slots:
          Size: 4 GB
          Speed: 1867 MHz
          Size: 4 GB
          Speed: 1867 MHz
Storage:
          Size: 250.14 GB (250,140,319,744 bytes)
          Media Name: APPLE SSD SM0256G Media
          Size: 250.14 GB (250,140,319,744 bytes)
          Medium Type: SSD
```

测试结果：
```shell

~ ❯❯❯ wrk -c 10 -d 10s -t10 http://localhost:9090
Running 10s test @ http://localhost:9090
  10 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency   339.99us    1.28ms  44.43ms   98.29%
    Req/Sec     4.49k   656.81     7.47k    73.36%
  449588 requests in 10.10s, 54.88MB read
Requests/sec:  44513.22
Transfer/sec:      5.43MB

~ ❯❯❯ wrk -c 10 -d 10s -t10 http://localhost:9090
Running 10s test @ http://localhost:9090
  10 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency   334.76us    1.21ms  45.47ms   98.27%
    Req/Sec     4.42k   633.62     6.90k    71.16%
  443582 requests in 10.10s, 54.15MB read
Requests/sec:  43911.68
Transfer/sec:      5.36MB

~ ❯❯❯ wrk -c 10 -d 10s -t10 http://localhost:9090
Running 10s test @ http://localhost:9090
  10 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency   379.26us    1.34ms  44.28ms   97.62%
    Req/Sec     4.55k   591.64     8.20k    76.37%
  455710 requests in 10.10s, 55.63MB read
Requests/sec:  45118.57
Transfer/sec:      5.51MB

```

多次测试的结果在4万左右的QPS浮动，响应时间最多也就是40ms左右，对于一个Web程序来说，这已经是很不错的成绩了，我们只是照抄了别人的示例代码，就完成了一个高性能的hello world服务器，是不是很有成就感？


这还只是家用PC，线上服务器大多都是24核心起，32G内存+，CPU基本都是Intel i7。所以同样的程序在服务器上运行会得到更好的结果。


这里的hello world服务没有任何业务逻辑。真实环境的程序要复杂得多，有些程序偏网络IO瓶颈，例如一些CDN服务、Proxy服务；有些程序偏CPU/GPU瓶颈，例如登陆校验服务、图像处理服务；有些程序瓶颈偏磁盘，例如专门的存储系统，数据库。不同的程序瓶颈会体现在不同的地方，这里提到的这些功能单一的服务相对来说还算容易分析。如果碰到业务逻辑复杂代码量巨大的模块，其瓶颈并不是三下五除二可以推测出来的，还是需要从压力测试中得到更为精确的结论。


对于IO/Network瓶颈类的程序，其表现是网卡/磁盘IO会先于CPU打满，这种情况即使优化CPU的使用也不能提高整个系统的吞吐量，只能提高磁盘的读写速度，增加内存大小，提升网卡的带宽来提升整体性能。而CPU瓶颈类的程序，则是在存储和网卡未打满之前CPU占用率先到达100%，CPU忙于各种计算任务，IO设备相对则较闲。


无论哪种类型的服务，在资源使用到极限的时候都会导致请求堆积，超时，系统hang死，最终伤害到终端用户。对于分布式的Web服务来说，瓶颈还不一定总在系统内部，也有可能在外部。非计算密集型的系统往往会在关系型数据库环节失守，而这时候Web模块本身还远远未达到瓶颈。


不管我们的服务瓶颈在哪里，最终要做的事情都是一样的，那就是流量限制。