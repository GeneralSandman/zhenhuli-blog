## 功能描述
封禁对象功能
1、图片需要根据配置来决定使用ACL，还是普通封禁
2、视频统一走ACL


## 请求
### 请求示例

```shell
PUT /block HTTP/1.1
Host: 审核服务地址
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/xml

<body>
{
    "objectType":"Image" // Image Video
    "appID":"",
    "ownerUin": "",
    "bucketID": "",
    "region":"",
    "object": "",
    "auditID":"" // 方便图片来选择使用哪种方式
}

```

## 响应

### 响应体

``` shell
{
    "code": 0,
    "message": "",
    "data":[]
}
```