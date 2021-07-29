

# Etcd学习笔记

![]()


> [!TIP|style:flat|label:tip]
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


etcd 介绍 https://juejin.cn/post/6844903984440803341


## Go 操作 Etcd

- Put Get
- Watch
- 租约
- keepAlive
- 分布式锁

https://www.liwenzhou.com/posts/Go/go_etcd/


etcdctl常用操作 https://juejin.cn/post/6844903977100787726



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


## RESTAPI 接口

curl -L http://82.156.245.21:2379/version | jq .

创建键值

curl http://82.156.245.21:2379/v2/keys/cqh -XPUT -d value="chenqionghe1"

过期时间

curl http://82.156.245.21:2379/v2/keys/k123 -XPUT -d value="v123" -d ttl=5 | jq .


创建目录

curl http://82.156.245.21:2379/v2/keys/gym -XPUT -d dir=true

curl http://82.156.245.21:2379/v2/keys/cqh | jq .

curl http://82.156.245.21:2379/v2/keys/gym | jq .

curl http://82.156.245.21:2379/v3/keys/q1mi | jq .


curl http://82.156.245.21:2379/v2/keys/gym/k1 -XPUT -d value="v1"





创建有序键值

curl http://82.156.245.21:2379/v2/keys/key-order -XPOST -d value="v1" | jq .

curl http://82.156.245.21:2379/v2/keys/key-order -XPOST -d value="v2" | jq .

curl http://82.156.245.21:2379/v2/keys/key-order -XPOST -d value="v3" | jq .

curl http://82.156.245.21:2379/v2/keys/key-order | jq .


etcd-browser 可视化界面 http://82.156.245.21:8000
docker run --rm  -d --name etcd-browser \
-p 8000:8000 \
--env ETCD_HOST=82.156.245.21 \
--env ETCD_PORT=2379 \
buddho/etcd-browser







列出所有集群成员
curl http://82.156.245.21:2379/v2/members | jq .

统计信息-查看leader
curl http://82.156.245.21:2379/v2/stats/leader | jq .

节点自身信息
curl http://82.156.245.21:2379/v2/stats/self | jq .

查看集群运行状态
curl http://82.156.245.21:2379/v2/stats/store | jq .



-----------


## 高可用分布式存储 etcd 的实现原理 

https://draveness.me/etcd-introduction/