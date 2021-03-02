## 功能描述
对象归为正常功能，归为正常功能需要做两个事情。
一、
1、图片根据配置来决定是ACL，还是解封
2、视频是通过ACL
二、
设置审核记录里的状态，保证查询时查不到对应的记录


## 请求
### 请求示例

```shell
PUT /normal HTTP/1.1
Host: 审核服务地址
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/json

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