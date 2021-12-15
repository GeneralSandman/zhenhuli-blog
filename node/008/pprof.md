# pprof 性能调优




要进行性能分析、数据分析和优化，首先想到的是 Go 开箱提供的一系列性能监控 API 和工具链包，如 pprof。

pprof 采样方式主要分为三种：

1. runtime/pprof：采集程序（非 Server）的运行数据进行分析。

2. net/http/pprof：采集 HTTP Server 的运行时数据进行分析，这个其实在上面的功能中包了一层提供了 HTTP 接口。

3. 通过运行测试用例来指定所需标识来进行采集。

首先采用运行时数据进行分析，监听端口为 9095


在 go代码中添加一下代码，

```

import (
    _ "net/http/pprof"
)

func main() {
    // 开启 pprof 性能监控
	go func() {
        _ = http.ListenAndServe("127.0.0.1:9095", nil)
    }()
}



```


```

wget http://11.179.224.25:9095/debug/pprof/profile

sz profile

go tool pprof -http=127.0.0.1:8068 profile

```


```


wget http://11.179.224.25:9095/debug/pprof/pprof/heap

sz heap

go tool pprof -http=127.0.0.1:8068 heap

```



```
 /root/go/bin/go-torch -u http://localhost:6060/ --seconds 120 -f cpu.svg
```
