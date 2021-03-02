## 功能描述
Describe Media Queues 搜索队列

## 请求
### 请求实例

```shell
GET /queue HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/xml

```

> Authorization: Auth String （详情请查阅 [请求签名](https://cloud.tencent.com/document/product/) 文档）。

### 请求头
#### 公共头部
该请求操作的实现使用公共请求头，了解公共请求头详情请参阅 [公共请求头部](https://cloud.tencent.com/document/product/) 文档。
#### 非公共头部
该请求操作无特殊的请求头部信息。

### 请求体
该请求的请求体为空。

#### 请求参数

| 名称       | 类型   | 描述                                                         | 必选 |
| ---------- | ------ | ------------------------------------------------------------ | ---- |
| queueIds   | string | 队列ID, 以,符号分割字符串                                    | 否   |
| state      | string | 1. Active 表示队列内的作业会被媒体转码服务调度转码执行<br/>2. Paused 表示队列暂停，作业不再会被媒体转码调度转码执行，队列内的所有作业状态维持在暂停状态，已经处于转码中的任务将继续转码，不受影响 | 否   |
| pageNumber | string | 第几页                                                       | 否   |
| pageSize   | string | 每页个数                                                     | 否   |

## 响应
### 响应头

#### 公共响应头
该响应包含公共响应头，了解公共响应头详情请参阅 [公共响应头部](https://cloud.tencent.com/document/product/) 文档。
#### 特有响应头
该响应无特殊的响应头。

### 响应体
该响应体返回为 **application/xml** 数据，当指定pageNumber和pageSize时包含完整节点数据的内容展示如下：

``` shell
<Response>
    <RequestId>NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=</RequestId>
    <TotalCount>1</TotalCount>
    <PageNumber>1</PageNumber>
    <PageSize>10</PageSize>
    <QueueList>
        <QueueId>A</QueueId>
        <Name></Name>
        <State>Active</State>
        <MaxSize>10000</MaxSize>
        <MaxConcurrent>10</MaxConcurrent>
        <UpdateTime></UpdateTime>
        <CreateTime></CreateTime>
        <NotifyConfig>
            <Url></Url>
            <Type></Type>
            <State></State>
            <Event></Event>
        </NotifyConfig>
    </QueueList>
</Response>
```

具体的数据内容如下：

| 节点名称（关键字） | 父节点 | 描述           | 类型      |
| :----------------- | :----- | :------------- | :-------- |
| Response           | 无     | 保存结果的容器 | Container |

Container 节点 Response 的内容：

| 节点名称（关键字） | 父节点   | 描述                           | 类型      |
| :----------------- | :------- | :----------------------------- | :-------- |
| RequestId          | Response | 请求的唯一ID                   | String    |
| TotalCount         | Response | 队列总数                       | Int       |
| PageNumber         | Response | 当前页数，同请求中的pageNumber | Int       |
| PageSize           | Response | 每页个数，同请求中的pageSize   | Int       |
| QueueList          | Response | 队列数组                       | Container |

Container节点QueueList的内容：

| 节点名称（关键字） | 父节点             | 描述                         | 类型      |
| :----------------- | :----------------- | :--------------------------- | :-------- |
| QueueId            | Response.QueueList | 队列ID                       | String    |
| Name               | Response.QueueList | 队列名字                     | String    |
| State              | Response.QueueList | 当前状态，Active 或者 Paused | String    |
| NotifyConfig       | Response.QueueList | 回调配置                     | Container |
| MaxSize            | Response.QueueList | 队列最大长度                 | Int       |
| MaxConcurrent      | Response.QueueList | 当前队列最大并行执行的任务数 | Int       |
| UpdateTime         | Response.QueueList | 更新时间                     | String    |
| CreateTime         | Response.QueueList | 创建时间                     | String    |

Container节点NotifyConfig的内容：

| 节点名称（关键字） | 父节点                          | 描述                              | 类型   |
| :----------------- | :------------------------------ | :-------------------------------- | :----- |
| Url                | Response.QueueList.NotifyConfig | 回调地址                          | String |
| State              | Response.QueueList.NotifyConfig | 开关状态，On 或者 Off             | String |
| Type               | Response.QueueList.NotifyConfig | 回调类型，Url                     | String |
| Event              | Response.QueueList.NotifyConfig | 任务完成:TaskFinish;工作流完成:WorkflowFinish | String |



该响应体返回为 **application/xml** 数据，当指定queueIds时包含完整节点数据的内容展示如下：

```shell
<Response>
    <RequestId>NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=</RequestId>
    <QueueList>
        <QueueId>A</QueueId>
        <Name></Name>
        <State>Active</State>
        <NotifyConfig>
            <Url></Url>
        </NotifyConfig>
    </QueueList>
    <NonExistPIDs>
        <QueueID>B</QueueID>
        <QueueID>C</QueueID>
    </NonExistPIDs>
</Response>
```

具体的数据内容如下：

| 节点名称（关键字） | 父节点 | 描述           | 类型      |
| :----------------- | :----- | :------------- | :-------- |
| Response           | 无     | 保存结果的容器 | Container |

Container 节点 Response 的内容：

| 节点名称（关键字） | 父节点   | 描述                             | 类型      |
| :----------------- | :------- | :------------------------------- | :-------- |
| RequestId          | Response | 请求的唯一ID                     | String    |
| QueueList          | Response | 队列数组，同上面解释的 QueueList | Container |
| NonExistPIDs       | Response | 不存在的队列ID列表               | Container |

Container 节点 NonExistPIDs的内容：

| 节点名称（关键字） | 父节点                | 描述   | 类型   |
| :----------------- | :-------------------- | :----- | :----- |
| QueueID            | Response.NonExistPIDs | 队列ID | String |

### 错误码

该请求操作无特殊错误信息，常见的错误信息请参见 [错误码](https://cloud.tencent.com/document/product/) 章节。

## 实际案例

### 请求

```shell
GET /queue?queueIds=A,B,C HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 0
Content-Type: application/xml

```

### 响应

```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 100
Connection: keep-alive
Date: Thu, 15 Jun 2017 12:37:29 GMT
Server: tencent-ci
x-ci-request-id: NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=

<Response>
    <RequestId>NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=</RequestId>
    <QueueList>
        <QueueID>A</QueueID>
        <Name></Name>
        <State>Active</State>
        <NotifyConfig>
            <Url></Url>
        </NotifyConfig>
    </QueueList>
    <NonExistPIDs>
        <QueueID>B</QueueID>
        <QueueID>C</QueueID>
    </NonExistPIDs>
</Response>
```

### 请求

```shell
GET /queue?pageSize=10&pageNumber=1 HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 0
Content-Type: application/xml

```

### 响应

```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 100
Connection: keep-alive
Date: Thu, 15 Jun 2017 12:37:29 GMT
Server: tencent-ci
x-ci-request-id: NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=

<Response>
    <RequestId>NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=</RequestId>
    <TotalCount>1</TotalCount>
    <PageNumber>1</PageNumber>
    <PageSize>10</PageSize>
    <QueueList>
        <QueueID>B</QueueID>
        <Name></Name>
        <State>Paused</State>
        <NotifyConfig>
            <Url></Url>
        </NotifyConfig>
    </QueueList>
</Response>
```