## 功能描述
审核记录查询


## 请求
### 请求示例

```shell
GET /auditings HTTP/1.1
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
| objectType |无|文件类型 Video、Image |String|是|
| region |无|bucket所在园区 |String|是|
| bucketID |无|bucket桶 |String|是|
| scene |无|审核场景 All、Porn、Terrorism、Politics、Ads|String|是|
| state |无| 审核结果 All、Normal、Possible、Convince | String |是|
| freeze |无| 冻结 All、Yes、No | String |是|
| orderByTime |无| Desc 或者 Asc。默认为 Desc。 | String |否|
| nextToken |无| 请求的上下文，用于翻页。上次返回的值。 | String |否|
| size |无| 拉取的最大任务数。默认为10。最大为100。 | Integer |否|
| startCreateTime |无| 上传时间大于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String |否|
| endCreateTime |无| 上传时间小于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String |否|
| object |无| 对象名称 |String|否|
| startScore |无| 分数大于的任务。 | Integer |否|
| endScore |无| 分数小于的任务。 | Integer |否|


## 响应

### 响应体

``` shell
{
    "code": 0,
    "message": "",
    "data": {
        "image": [{
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
            }
        }],
        "video": [{
            "recordID": "",
            "object": "",
            "url": "",
            "image": "",
            "createTime": "",
            "state": "",
            "freeze": "",
            "size": 1,
            "result": {
                "porn": {
                    "num": 1
                },
                "terrorism": {
                    "num": 1
                },
                "politics": {
                    "num": 1
                },
                "ads": {
                    "num": 1
                }
            }
        }],
        "imageRules": {
            "normal": {
                "min": 0,
                "max": 60
            },
            "possible": {
                "min": 60,
                "max": 90
            },
            "convince": {
                "min": 90,
                "max": 100
            }
        },
        "videoRules": {
            "normal": {
                "min": 0,
                "max": 1
            },
            "possible": {
                "min": 1,
                "max": 3
            },
            "convince": {
                "min": 3,
                "max": -1
            }
        },
        "nextToken": ""
    }
}
```