## 功能描述
Generate Snapshot 接口用来获取媒体文件某个时间的截图。输出的截图统一为 jpeg 格式。

## 请求
### 请求示例

```shell
POST /snapshot HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-type: application/xml

<body>
```

> Authorization: Auth String（详情请参阅 [请求签名](https://cloud.tencent.com/document/product/) 章节）

### 请求头

#### 公共头部
该请求操作的实现使用公共请求头，了解公共请求头详情请参阅 [公共请求头部](https://cloud.tencent.com/document/product/) 章节。
#### 非公共头部
该请求操作无特殊的请求头部信息。

### 请求体
该 API 接口请求的请求体具体节点内容为：
```shell
<Request>
  <Input>
    <Object></Object>
  </Input>
  <Time></Time>
  <Width></Width>
  <Height></Height>
  <Mode></Mode>
  <Rotate></Rotate>
  <Format></Format>
  <Output>
    <Region></Region>
    <Bucket></Bucket>
    <Object></Object>
  </Output>
</Request>
```
具体的数据内容如下：

|节点名称（关键字）|父节点|描述|类型|必选|
|:---|:-- |:--|:--|:--|
| Request |无| 保存 Generate Snapshot 请求的容器 | Container |是|

Container 节点 Request 的内容：

|节点名称（关键字）|父节点|描述|类型|必选|
|:---|:-- |:--|:--|:--|
| Input | Request | 媒体文件 位置信息 |  Container |是|
| Time | Request | 截取哪个时间点的内容，单位 秒 | Float |是|
| Output | Request | 截图保存的 位置信息 |  Container |是|
| Width | Request | 截图的宽。默认为0。 | Int |否|
| Height | Request | 截图的高。默认为0。<br/>Width和Height都为0时表示使用视频的宽高，如果单个为0，则以另外一个值按视频宽高比例自动适应。 | Int |否|
| Format | Request | 截图的格式，支持 jpg和png，默认jpg。 | String |否|
| Mode | Request | 截帧方式。<br/>keyframe：截取指定时间点之前的最近的一个关键帧；<br/>exactframe：截取指定时间点的帧。<br/>默认值为 exactframe。 | String |否|
| Rotate | Request | 图片旋转方式。<br/>auto：按视频旋转信息进行自动旋转；<br/>off：不旋转。<br/>默认值为 auto。 | String |否|

Container 节点 Input的内容：

| 节点名称（关键字） | 父节点        | 描述        | 类型   | 必选 |
| :----------------- | :------------ | :---------- | :----- | :--- |
| Object             | Request.Input | 文件 的名字 | String | 是   |

Container 节点 Output 的内容：

|节点名称（关键字）|父节点|描述|类型|必选|
|:---|:-- |:--|:--|:--|
| Region | Request.Output | 存储通所在的园区 |  String |是|
| Bucket | Request.Output | 文件所属的 COS存储桶 |  String |是|
| Object | Request.Output | 文件 的名字 |  String |是|


## 响应
### 响应头
#### 公共响应头
该响应包含公共响应头，了解公共响应头详情请参阅 [公共响应头部](https://cloud.tencent.com/document/product/) 章节。
#### 特有响应头
该响应无特殊的响应头。

### 响应体
该响应体返回为 **application/xml** 数据，包含完整节点数据的内容展示如下：

```shell
<Response>
  <Output>
    <Region></Region>
    <Bucket></Bucket>
    <Object></Object>
  </Output>
</Response>
```

具体的数据内容如下：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| Response |无| 保存结果的容器 | Container |

Container 节点 Response 的内容：

|节点名称（关键字）|父节点|描述|类型|
|:---|:-- |:--|:--|
| Output | Request | 截图保存的 位置信息 |  Container |是|

Container 节点 Output 的内容：

|节点名称（关键字）|父节点|描述|类型|必选|
|:---|:-- |:--|:--|:--|
| Region | Response.Output | 存储桶所在的园区 |  String |是|
| Bucket | Response.Output | 文件所属的 COS存储桶 |  String |是|
| Object | Response.Output | 文件 的名字 |  String |是|

### 错误码
该请求操作无特殊错误信息，常见的错误信息请参见 [错误码](https://cloud.tencent.com/document/product/) 章节。


## 实际案例

### 请求
```shell
POST /snapshot HTTP/1.1
Host: bucket-1250000000.ci.ap-beijing.myqcloud.com
Date: Fri, 10 Mar 2016 09:45:46 GMT
Authorization: q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1484213027;32557109027&q-key-time=1484213027;32557109027&q-header-list=host&q-url-param-list=acl&q-signature=dcc1eb2022b79cb2a780bf062d3a40e120b40652
Content-Length: 552
Content-Type: application/xml

<Request>
  <Input>
    <Object>video-for-test.mp4</Object>
  </Input>
  <Time>10</Time>
  <Output>
    <Region>ap-beijing</Region>
    <Bucket>ci-output-1250000000</Bucket>
    <Object>snapshot/video-for-test-snapshot.jpg</Object>
  </Output>
</Request>
```
### 响应
```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 266
Connection: keep-alive
Date: Fri, 10 Mar 2016 09:45:46 GMT
Server: tencent-ci
x-ci-request-id: NTg3NzRiMjVfYmRjMzVfMTViMl82ZGZmNw==

<Response>
  <Output>
    <Region>ap-beijing</Region>
    <Bucket>ci-output-1250000000</Bucket>
    <Object>snapshot/video-for-test-snapshot.jpg</Object>
  </Output>
</Response>
```

