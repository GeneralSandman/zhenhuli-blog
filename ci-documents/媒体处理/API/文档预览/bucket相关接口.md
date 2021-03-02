# bucket 接口

## bucket权限控制


#### 1.开通bucket文档预览功能

* 接口地址

```
<BucketName-APPID>.ci.<Region>.myqcloud.com/docbucket
```

* 请求方式

```
POST
```

* 请求示例

```

POST /docbucket HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String

```

* 返回参数

```
<Response>
        <RequestId>RequestId</RequestId>
        <DocBucket>
                <Name>BucketName-APPID</Name>
                <CreateTime>Time</CreateTime>
                <Region>Region</Region>
                <AliasBucketId/>
                <BucketId>BucketName-APPID</BucketId>
        </DocBucket>
</Response>
```

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| RequestId    | string    | 请求id   |
| DocBucket    | object    | bucket对象信息   |

* DocBucket字段说明

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| Name | string | bucket名称 |
| Region    | string | bucket所在区域 |
| BucketId    | string | bucket id |

#### 2. 获取已开通文档预览功能的bucket列表

* 接口地址

```
<BucketName-APPID>.ci.<Region>.myqcloud.com/docbucket
```

* 请求方式

```
GET
```

* 请求示例 

```
GET /docbucket?pageNumber=1&pageSize=2 HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String
```
* 请求参数

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| regions| string |地区信息，以,分隔字符串，支持All,ap-shanghai,ap-beijing|
| bucketNames| string |bucket名字，以,分隔，支持多bucket，精确搜索|
| bucketName| string |bucket名字前缀，前缀搜索|
| pageNumber| int |页码（默认第一页）|
| pageSize| int | 每页条数（默认十条） |

* 返回示例

```
<Response>
        <TotalCount>1</TotalCount>
        <RequestId>RequestId</RequestId>
        <PageNumber>1</PageNumber>
        <PageSize>2</PageSize>
        <DocBucketList>
                <Name>BucketName-APPID</Name>
                <CreateTime>Time</CreateTime>
                <Region>Region</Region>
                <AliasBucketId/>
                <BucketId>BucketName-APPID</BucketId>
        </DocBucketList>
</Response>
```

* 返回参数
| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| TotalCount    | int    | 总个数   |
| RequestId | string | 请求id |
| PageNumber    | int | 页码 |
| PageSize    | int | 每页条数 |
| DocBucketList    | object | 桶列表对象 |

* DocBucketList 参数说明
| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| Name | string | bucket名称 |
| CreateTime    | string | 开通时间|
| Region    | string | bucket所在区域 |
| BucketId    | string | bucket id |

#### 3.关闭bucket文档预览功能

* 接口地址

```
<BucketName-APPID>.ci.<Region>.myqcloud.com/docbucket
```

* 请求方式

```
DELETE
```

* 请求示例

```
DELETE /docbucket HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String
```

* 返回参数

```
<Response>
        <RequestId>RequestId</RequestId>
        <BucketName>BucketName</BucketName>
</Response>
```
| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| RequestId    | string    | 请求id   |
| BucketName    | string    | bucket名  |