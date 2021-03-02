## 功能描述
Describe MediaBuckets 查询媒体Bucket

## 请求
### 请求实例

```shell
GET /mediabucket HTTP/1.1
Host: ci.<Region>.myqcloud.com
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
<table>
   <tr>
      <th nowrap="nowrap">名称</th>
      <th>类型</th>
      <th>描述</th>
      <th>必选</th>
   </tr>
   <tr>
      <td>regions</td>
      <td>string</td>
      <td>地区信息，以,分隔字符串，支持All,ap-shanghai,ap-beijing</td>
      <td>否</td>
   </tr>
   <tr>
      <td>bucketNames</td>
      <td>string</td>
      <td>bucket名字，以,分隔，支持多bucket，精确搜索</td>
      <td>否</td>
   </tr>
   <tr>
      <td>bucketName</td>
      <td>string</td>
      <td>bucket名字前缀，前缀搜索</td>
      <td>否</td>
   </tr>
   <tr>
      <td>pageNumber</td>
      <td>string</td>
      <td>第几页</td>
      <td>否</td>
   </tr>
   <tr>
      <td>pageSize</td>
      <td>string</td>
      <td>每页个数</td>
      <td>否</td>
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

``` shell
<Response>
    <RequestId>NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=</RequestId>
    <TotalCount>1</TotalCount>
    <PageNumber>1</PageNumber>
    <PageSize>10</PageSize>
    <MediaBucketList>
        <BucketId></BucketId>
        <Region></Region>
        <CreateTime></CreateTime>
    </MediaBucketList>
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
| TotalCount         | Response | 媒体Bucket总数                 | Int       |
| PageNumber         | Response | 当前页数，同请求中的pageNumber | Int       |
| PageSize           | Response | 每页个数，同请求中的pageSize   | Int       |
| MediaBucketList    | Response | 媒体Bucket列表                 | Container |

Container节点MediaBucketList的内容：

| 节点名称（关键字） | 父节点                   | 描述                   | 类型   |
| :----------------- | :----------------------- | :--------------------- | :----- |
| BucketId           | Response.MediaBucketList | 存储桶ID               | String |
| Name               | Response.MediaBucketList | 存储桶名字，同BucketId | String |
| Region             | Response.MediaBucketList | 所在的园区             | String |
| CreateTime         | Response.MediaBucketList | 创建时间               | String |

### 错误码

该请求无特有错误信息，常见的错误信息请参阅 [错误码](https://cloud.tencent.com/document/product/) 文档。

## 实际案例

### 请求

```shell
GET /mediabucket HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:ci.ap-beijing.myqcloud.com
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
    <MediaBucketList>
        <BucketId></BucketId>
        <Region></Region>
        <CreateTime></CreateTime>
    </MediaBucketList>
    <MediaBucketList>
        <BucketId></BucketId>
        <Region></Region>
        <CreateTime></CreateTime>
    </MediaBucketList>
</Response>
```