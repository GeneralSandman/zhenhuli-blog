## 功能描述
审核记录查询


## 请求
### 请求示例

```shell
GET /videoinfo HTTP/1.1
Host: 审核服务地址
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/json

<body>
```

参数的具体内容如下：

|节点名称（关键字）|父节点|描述|类型|必选|
|:---|:-- |:--|:--|:--|
| recordID |无| 审核记录ID |String|是|


## 响应

### 响应体

``` shell
{
    "code": 0,
    "message": "",
    "data":{
        "image":[
            "recordID": "",
            "object": "",
            "url": "",
            "createTime": "",
            "state": "",
            "freeze": "",
            "size": 1,
            "result": {
                "porn": {
                    "code": 1,
                    "hitFlag": "",
                    "score": 100,
                    "label": ""
                },
                "terrorism": {
                    "code": 1,
                    "hitFlag": "",
                    "score": 100,
                    "label": ""
                },
                "politics": {
                    "code": 1,
                    "hitFlag": "",
                    "score": 100,
                    "label": ""
                },
                "ads": {
                    "code": 1,
                    "hitFlag": "",
                    "score": 100,
                    "label": ""
                }
            }]
    }
}
```