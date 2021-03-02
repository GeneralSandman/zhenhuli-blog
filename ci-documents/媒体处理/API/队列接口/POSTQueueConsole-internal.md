## 功能描述
POST Queue 更新队列 控制台专用不对外

## 请求
### 请求实例

```shell
POST /queue/p8eb46b8cc1a94bc09512d16c5c4f4d3a?update HTTP/1.1
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
    <Name>Queue Name</Name>
    <State></State>
</Request>
或者
<Request>
    <Name>Queue Name</Name>
    <NotifyConfig>
        <State>On</State>
        <Type>Url</Type>
        <Url></Url>
        <Event>TaskFinish<Event>
    </NotifyConfig>
</Request>
```

具体数据描述如下：
<table>
   <tr>
      <th nowrap="nowrap">节点名称（关键字）</th>
      <th>父节点</th>
      <th>描述</th>
      <th>类型</th>
      <th>必选</th>
   </tr>
   <tr>
      <td>Request</td>
      <td>无</td>
      <td>保存请求的容器</td>
      <td>Container</td>
      <td>是</td>
   </tr>
</table>

Container 类型 Request 的具体数据描述如下：
<table>
   <tr>
      <th nowrap="nowrap">节点名称（关键字）</th>
      <th>父节点</th>
      <th>描述</th>
      <th>类型</th>
      <th>必选</th>
      <th>限制</th>
   </tr>
   <tr>
      <td>Name</td>
      <td>Request</td>
      <td>模板名称</td>
      <td>String</td>
      <td>否</td>
      <td>长度限制100字符</td>
   </tr>
   <tr>
      <td>State</td>
      <td>Request</td>
      <td>管道状态</td>
      <td>String</td>
      <td>否</td>
      <td>
        1. Active 表示管道内的作业会被媒体转码服务调度转码执行
        2. Paused 表示管道暂停，作业不再会被媒体转码调度转码执行，管道内的所有作业状态维持在已提交状态，已经处于转码中的任务将继续转码，不受影响
      </td>
   </tr>
   <tr>
      <td>NotifyConfig</td>
      <td>Request</td>
      <td>通知渠道</td>
      <td>Container</td>
      <td>否</td>
      <td>第三方回调Url</td>
   </tr>
</table>

Container 类型 NotifyConfig 的具体数据描述如下：
<table>
   <tr>
      <th nowrap="nowrap">节点名称（关键字）</th>
      <th>父节点</th>
      <th>描述</th>
      <th>类型</th>
      <th>必选</th>
      <th>限制</th>
   </tr>
   <tr>
      <td>Url</td>
      <td>Request.NotifyConfig</td>
      <td>回调配置</td>
      <td>String</td>
      <td>否</td>
      <td>长度限制100字符</td>
   </tr>
   <tr>
      <td>Type</td>
      <td>Request.NotifyConfig</td>
      <td>回调类型，普通回调:Url</td>
      <td>String</td>
      <td>否</td>
      <td>长度限制100字符</td>
   </tr>
   <tr>
      <td>Event</td>
      <td>Request.NotifyConfig</td>
      <td>任务完成:TaskFinish;工作流完成:WorkflowFinish</td>
      <td>String</td>
      <td>否</td>
      <td>长度限制100字符</td>
   </tr>
      <tr>
      <td>State</td>
      <td>Request.NotifyConfig</td>
      <td>开关，Off，On</td>
      <td>String</td>
      <td>否</td>
      <td>长度限制100字符</td>
   </tr>
</table>

## 响应
### 响应头

#### 公共响应头
该响应包含公共响应头，了解公共响应头详情请参阅 [公共响应头部](https://cloud.tencent.com/document/product/) 文档。
#### 特有响应头
该响应无特殊的响应头。

### 响应体
该响应体返回为 **application/xml** 数据，包含完整节点数据的内容展示如下：

```shell
<Response>
    <RequestId>NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=</RequestId>
    <Queue>
        <QueueID></QueueID>
        <Name></Name>
        <State>Active</State>
        <NotifyConfig>
            <Url>mts-topic-1</Url>
            <Type></Type>
            <Event><Event>
        </NotifyConfig>
        <CreateTime></CreateTime>
        <UpdateTime></UpdateTime>
    </Queue>
</Response>
```

### 错误码
该请求无特有错误信息，常见的错误信息请参阅 [错误码](https://cloud.tencent.com/document/product/) 文档。

## 实际案例

### 请求

```shell
POST /queue/p8eb46b8cc1a94bc09512d16c5c4f4d3a?update HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 1666
Content-Type: application/xml

<Request>
    <Name>Queue Name</Name>
    <QueueID></QueueID>
    <State></State>
</Request>

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
    <Queue>
        <QueueID></QueueID>
        <Name></Name>
        <State>Active</State>
        <NotifyConfig>
            <Type></Type>
            <Url></Url>
            <Event><Event>
        </NotifyConfig>
        <CreateTime></CreateTime>
        <UpdateTime></UpdateTime>
    </Queue>
</Response>
```