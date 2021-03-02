## 功能描述
隐私合规记录查询


## 请求
### 请求示例

```shell
GET /sensitivedocuments HTTP/1.1
Host: 服务地址
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/json

<body>
```

参数的具体内容如下：

|节点名称（关键字）|父节点|描述|类型|必选|
|:---|:-- |:--|:--|:--|
| region |无|bucket所在园区 |String|是|
| bucketID |无|bucket桶 |String|是|
| orderByTime |无| Desc 或者 Asc。默认为 Desc。 | String |否|
| offset |无| 查询的开始偏移量。默认为0。 | Integer |否|
| size |无| 拉取的最大记录数。默认为10。最大为100。 | Integer |否|
| startCreateTime |无| 上传时间大于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String |否|
| endCreateTime |无| 上传时间小于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String |否|
| object |无| 对象名称 |String|否|
| level |无| 敏感等级。取值 high，middle，low之一。不设置代表全部。 | String |否|
| type |无| 敏感类型。1=身份证号，2=纳税人识别号，3=组织机构编码，4=银行卡号，5=工商注册号，6=军官证，7=电子邮箱，8=车牌号，9=手机号。不设置代表全部。 | Integer |否|
| regulation |无| 合规类型。1=GDPR，2=等保合规，3=网络安全法。不设置代表全部。 | Integer |否|


## 响应

### 响应体

``` shell
{
    "code": 0,
    "message": "",
    "data": {
        "documents": [{
            "recordID": "sd123kdj3is3ufj4mskdkfk4ls",
            "object": "abc.txt",
            "eTag": "sssffessssfefff",
            "createTime": "2020-06-06T12:12:12+0800",
            "level": "middle",
            "hitType": [1,2],
            "regulations": [1,2,3]
        }],
        "totalNum": 123
    }
}
```

回包中data具体内容如下：

| 节点名称（关键字） | 描述                     | 类型              | 必选 |
| :----------------- | :----------------------- | :---------------- | :--- |
| documents          | 文档详细信息数组。       | Array of Document | 是   |
| totalNum           | 符合查询条件的记录总数。 | Integer           | 是   |

Document的内容如下：

| 节点名称（关键字） | 描述                                                         | 类型             | 必选 |
| :----------------- | :----------------------------------------------------------- | :--------------- | :--- |
| recordID           | 该记录的唯一Key。                                            | String           | 是   |
| object             | object名字。                                                 | String           | 是   |
| eTag               | 该object的ETag。                                             | String           | 是   |
| createTime         | 该object的检查时间。格式为：%Y-%m-%dT%H:%m:%S%z              | String           | 是   |
| level              | 敏感等级。取值 high，middle，low之一。                       | String           | 是   |
| hitType            | 命中的隐私类型数组。1=身份证号，2=纳税人识别号，3=组织机构编码，4=银行卡号，5=工商注册号，6=军官证，7=电子邮箱，8=车牌号，9=手机号。 | Array of Integer | 是   |
| regulations        | 命中的合规类型数组。1=GDPR，2=等保合规，3=网络安全法。       | Array of Integer | 是   |
