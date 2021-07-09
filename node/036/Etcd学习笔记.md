

# Etcd学习笔记

![]()


> [!TIP|style:flat|label:引用头]
> Etcd 一些学习笔记

## etcd介绍
etcd是使用Go语言开发的一个开源的、高可用的分布式key-value存储系统，可以用于配置共享和服务的注册和发现。

类似项目有zookeeper和consul。

etcd具有以下特点：
- 完全复制：集群中的每个节点都可以使用完整的存档
- 高可用性：Etcd可用于避免硬件的单点故障或网络问题
- 一致性：每次读取都会返回跨多主机的最新写入
- 简单：包括一个定义良好、面向用户的API（gRPC）
- 安全：实现了带有可选的客户端证书身份验证的自动化TLS
- 快速：每秒10000次写入的基准速度
- 可靠：使用Raft算法实现了强一致、高可用的服务存储目录


## Go 操作 Etcd

- Put Get
- Watch
- 租约
- keepAlive
- 分布式锁

https://www.liwenzhou.com/posts/Go/go_etcd/



## 如何搭建一个Etcd集群

- 什么是ETCD
- 一.安装
- 二.搭建单机版
- 三.搭建集群版
- 四.监听功能-watch
- 五.使用rest api
- 六.可视化界面
  - etcd-browser
  - etcdkeeper

https://www.cnblogs.com/chenqionghe/p/10503840.html

