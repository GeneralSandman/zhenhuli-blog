## 功能描述
Create Auditing Jobs 接口用来提交一个审核任务。

## 请求
### 请求示例

```shell
POST /video/auditing HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/xml

<body>
```

> Authorization: Auth String （详情请查阅 [请求签名](https://cloud.tencent.com/document/product/) 文档）。


### 请求头
#### 公共头部
该请求操作的实现使用公共请求头，了解公共请求头详情请参阅 [公共请求头部](https://cloud.tencent.com/document/product/) 文档。
#### 非公共头部
该请求操作无特殊的请求头部信息。

### 请求体
该请求操作的实现需要有如下请求体。

```shell
<Request>
  <Input>
    <Object></Object>
  </Input>
  <Conf>
    <DetectType>Porn,Terrorism,Politics,Ads</DetectType>
    <Snapshot>
        <Mode>Interval</Mode>
        <TimeInterval></TimeInterval>
        <Count></Count>
    </Snapshot>
    <Callback></Callback>
  </Conf>
</Request>
```

具体的数据描述如下：

| 节点名称（关键字） | 父节点 | 描述           | 类型      | 必选 |
| ------------------ | ------ | -------------- | --------- | ---- |
| Request            | 无     | 保存请求的容器 | Container | 是   |

Container 类型 Request 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述                                                     | 类型      | 必选 |
| ------------------ | ------- | -------------------------------------------------------- | --------- | ---- |
| Input              | Request | 待操作的媒体信息                                         | Container | 是   |
| Conf               | Request | 操作规则                                                 | Container | 是   |

Container 类型 Input 的具体数据描述如下：

| 节点名称（关键字） | 父节点        | 描述            | 类型   | 必选 |
| ------------------ | ------------- | --------------- | ------ | ---- |
| Object             | Request.Input | 媒体文件 的名字 | String | 是   |

Container 类型 Conf 的具体数据描述如下：

| 节点名称（关键字） | 父节点            | 描述                                                         | 类型      | 必选 |
| ------------------ | ----------------- | ------------------------------------------------------------ | --------- | ---- |
| DetectType          | Request.Conf | 审核类型  涉黄Porn、涉暴恐Terrorism、政治敏感Politics、广告Ads, 可以传多种类型 | string | 是   |
| Snapshot            | Request.Conf | 截帧配置                   | Container | 是   |
| Callback            | Request.Conf | 回调地址，以http://或者https://开头的地址 | string | 否   |

Container 类型 Snapshot 的具体数据描述如下：

| 节点名称（关键字） | 父节点                      | 描述                                   | 类型      | 必选 |
| ------------------ | :-------------------------- | -------------------------------------- | --------- | ---- |
| Mode               | Request.Conf.Snapshot | 截帧模式, Interval 表示间隔模式 Average 表示平均模式 Fps 表示固定帧率.<br> Interval模式：TimeInterval，Count参数生效。当设置Count，未设置TimeInterval时，表示截取所有帧，共Count张图片.<br> Average模式：Count参数生效。表示整个视频，按平均间隔截取共Count张图片.<br> Fps模式: TimeInterval表示每秒截取多少帧，Count表示共截取多少帧 | Container | 否   |
| Count         |  Request.Conf.Snapshot | 截图数量, 范围:(0 10000] | string | 否   |
| TimeInterval | Request.Conf.Snapshot | 截图频率, 范围:(0 60], 单位为秒, 支持float格式，执行精度精确到毫秒 | string | 否 |

## 响应

### 响应头

#### 公共响应头
该响应包含公共响应头，了解公共响应头详情请参阅 [公共响应头部](https://cloud.tencent.com/document/product/) 文档。
#### 特有响应头
该响应无特殊的响应头。

### 响应体
该响应体返回为 **application/xml** 数据，包含完整节点数据的内容展示如下：

``` shell
<Response>
  <JobsDetail>
    <JobId></JobId>
    <State></State>
    <CreationTime></CreationTime>
  </JobsDetail>
</Response>
```

具体的数据内容如下：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| Response |无| 保存结果的容器 | Container |

Container 节点 Response 的内容：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| JobsDetail | Response | 任务的详细信息 |  Container |


Container 节点 JobsDetail 的内容：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| JobId | Response.JobsDetail | 新创建任务的ID |  String |
| State | Response.JobsDetail | 任务的状态，为 Submitted、Snapshoting、Success、Failed、Auditing其中一个 |  String |
| CreationTime | Response.JobsDetail | 任务的创建时间 |  String |


### 错误码
常见的错误信息请参阅 [错误码](https://cloud.tencent.com/document/product/) 文档。

## 实际案例


### 请求

```shell
POST /video/auditing HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 166
Content-Type: application/xml

<Request>
  <Input>
    <Object>a.mp4</Object>
  </Input>
  <Conf>
    <DetectType>Porn,Terrorism,Politics,Ads</DetectType>
    <Snapshot>
        <Mode>Interval</Mode>
        <Start>0.5</Start>
        <TimeInterval>100.5</TimeInterval>
        <Count>100</Count>
    </Snapshot>
    <Callback>http://callback.com/</Callback>
  </Conf>
</Request>
```

### 响应

```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 230
Connection: keep-alive
Date: Thu, 15 Jun 2017 12:37:29 GMT
Server: tencent-ci
x-ci-request-id: NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=

<Response>
  <JobsDetail>
    <JobId>vab1ca9fc8a3ed11ea834c525400863904</JobId>
    <State>Submitted</State>
    <CreationTime>2019-07-07T12:12:12+0800</CreationTime>
  </JobsDetail>
</Response>
```
