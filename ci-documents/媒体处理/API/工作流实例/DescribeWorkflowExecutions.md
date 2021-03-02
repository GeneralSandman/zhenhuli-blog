## 功能描述
Describe WorkflowExecution 工作流实例列表

## 请求
### 请求实例

```shell
GET /workflowexecution HTTP/1.1
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

|参数名称（关键字）|描述|类型|必选|
|:---|:--|:--|:--|
|workflowId|工作流ID        |string|是|
|name|文件名称              |string|否|
|orderByTime|Desc 或者 Asc。默认为 Desc。|string|否|
|size| 拉取的最大任务数。默认为10。最大为100。 |string|否|
|states|工作流实例状态，以,分割支持多状态<br> All，Success，Failed，Running，Cancel。默认为All|string|否|
|startCreationTime | 拉取创建时间大于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String |否|
|endCreationTime | 拉取创建时间小于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String |否|
|nextToken | 请求的上下文，用于翻页。下一页输入token。 | String |否|

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
  <WorkflowExecutionList>
    <RunId>37145b2919714156bd97f91dc03fa2b4</RunId>
    <WorkflowId>we65e4d260e1042debdfb7e4560a19d3d</WorkflowId>
    <State>Success</State>
    <CreationTime>2019-07-07T12:12:12+0800</CreateTime>
    <Object>https://20180109-1253960454.cos.ap-beijing.myqcloud.com/mars_white_test.mp4</Object>
  </WorkflowExecutionList>
  <NextToken></NextToken>
</Response>
```

具体的数据内容如下：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| Response |无| 保存结果的容器 | Container |

Container 节点 Response 的内容：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| WorkflowExecutionList | Response | 工作流实例详细信息 |  Container |
| NextToken | Response | 翻页的上下文Token |  string |

Container 节点 WorkflowExecutionList 的内容：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| RunId | Response.WorkflowExecutionList | 工作流实例ID | string |
| WorkflowId | Response.WorkflowExecutionList | 工作流ID | string |
| State | Response.WorkflowExecutionList | 工作流实例状态 | string |
| CreateTime | Response.WorkflowExecutionList | 创建时间 | string |
| Object | Response.WorkflowExecutionList | cos对象地址 | string |


### 错误码
该请求操作可能会出现如下错误信息，常见的错误信息请参阅 [错误码](https://cloud.tencent.com/document/product/) 文档。


## 实际案例

### 请求

```shell
GET /workflowexecution?workflowId=we65e4d260e1042debdfb7e4560a19d3d HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com

```
### 响应

```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 666
Connection: keep-alive
Date: Thu, 15 Jun 2017 12:37:29 GMT
Server: tencent-ci
x-ci-request-id: NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=

<Response>
  <WorkflowExecutionList>
    <RunId>37145b2919714156bd97f91dc03fa2b4</RunId>
    <WorkflowId>we65e4d260e1042debdfb7e4560a19d3d</WorkflowId>
    <State>Success</State>
    <CreateTime>2019-07-07T12:12:12+0800</CreateTime>
    <Object>https://20180109-1253960454.cos.ap-beijing.myqcloud.com/mars_white_test.mp4</Object>
  </WorkflowExecutionList>
  <WorkflowExecutionList>
    <RunId>47145b2929714156bd97f91dc03fa2b5</RunId>
    <WorkflowId>we65e4d260e1042debdfb7e4560a19d3d</WorkflowId>
    <State>Success</State>
    <CreateTime>2019-07-07T12:12:12+0800</CreateTime>
    <Object>https://20180109-1253960454.cos.ap-beijing.myqcloud.com/_test.mp4</Object>
  </WorkflowExecutionList>
  <NextToken>e65e4d260e1042debdfb7e4560a19d3d</NextToken>
</Response>
```