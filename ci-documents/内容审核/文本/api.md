## 功能描述
文本的审核记录查询


## 请求

### 请求示例

```shell
GET /text/records HTTP/1.1
Host: 审核服务地址
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>

```

参数的具体内容如下：

| 节点名称（关键字） | 父节点 | 描述                                            | 类型    | 必选 |
| :----------------- | :----- | :---------------------------------------------- | :------ | :--- |
| region             | 无     | bucket所在园区                                  | String  | 是   |
| bucketID           | 无     | bucket桶                                        | String  | 是   |
| scene              | 无     | 审核场景 All、Porn、Illegal、Terrorism、Politics、Ads、Abuse | String  | 是   |
| state              | 无     | 审核结果 All、Normal、Possible、Convince        | String  | 是   |
| freeze             | 无     | 冻结 All、Yes、No                               | String  | 是   |
| orderByTime        | 无     | Desc 或者 Asc。默认为 Desc。                    | String  | 否   |
| nextToken          | 无     | 查询的偏移量，offset+size最大10000。            | String  | 否   |
| size               | 无     | 拉取的最大任务数。默认为10。最大为100。         | Integer | 否   |
| startCreateTime    | 无     | 上传时间大于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String  | 否   |
| endCreateTime      | 无     | 上传时间小于该时间。格式为：%Y-%m-%dT%H:%m:%S%z | String  | 否   |
| object             | 无     | 对象名称                                        | String  | 否   |
| startScore         | 无     | 分数大于的任务。                                | Integer | 否   |
| endScore           | 无     | 分数小于的任务。                                | Integer | 否   |


## 响应

### 响应体

``` json
{
    "RequestID": "NWZmNDRlZDdfOTBmYTUwNjRfNTc2MF8y",
    "Code": 0,
    "Message": "success",
    "Data": {
        "Text": [
            {
                "recordID": "ta7b2c05f04f0311eb851c5254008618d9",
                "object": "all__.txt",
                "createTime": "2021-01-05T11:09:53+08:00",
                "modifyState": 0,
                "freeze": "Yes",
                "size": 3853,
                "result": {
                    "Porn": {
                        "hitFlag": 3,
                        "num": 1,
                        "possibleNum": 0,
                        "label": "xx,xx,xx"
                    },
                    "Illegal": {
                        "hitFlag": 3,
                        "num": 1,
                        "possibleNum": 0,
                        "label": "xx,xx,xx"
                    },
                    "Terrorism": {
                        "hitFlag": 3,
                        "num": 1,
                        "possibleNum": 0,
                        "label": "xx,xx,xx"
                    },
                    "Politics": {
                        "hitFlag": 3,
                        "num": 1,
                        "possibleNum": 0,
                        "label": "xx,xx,xx"
                    },
                    "Ads": {
                        "hitFlag": 1,
                        "num": 0,
                        "possibleNum": 1,
                        "label": "xx,xx,xx"
                    },
                    "Abuse": {
                        "hitFlag": 3,
                        "num": 1,
                        "possibleNum": 0,
                        "label": "xx,xx,xx"
                    }
                }
            }
        ],
        "totalNum": 30
    }
}
```

Data节点详情

| 节点名称（关键字）  | 描述              | 类型     | 必选 |
| :----------------- | :--------------- | :------ | :--- |
| Text               | 文本审核详情      | Array   | 否   |
| totalNum           | 查询结果数量      | Integer | 是   |

Text节点详情

| 节点名称（关键字）   | 描述                    | 类型    | 必选 |
| :----------------- | :---------------------- | :------ | :--- |
| recordID           | 该记录的uid              | String  | 是   |
| object             | 文件全路径名字           | String  | 是   |
| createTime         | 该文件的审核时间         | String  | 是   |
| modifyState        | 客户判定结果，1:正常。    | String  | 是   |
| freeze             | 冻结状态。Yes/No。       | String  | 是   |
| size               | 敏感分值。               | String  | 是   |
| result             | 敏感详情                 | Object  | 是   |

result节点详情

| 节点名称（关键字）   | 描述           | 类型    | 必选 |
| :----------------- | :------------- | :------ | :--- |
| Porn               | 涉黄           | Object  | 否   |
| Illegal            | 违法           | Object  | 否   |
| Terrorism          | 涉暴恐         | Object  | 否   |
| Politics           | 政治敏感       | Object  | 否   |
| Ads                | 广告           | Object  | 否   |
| Abuse              | 谩骂           | Object  | 否   |

敏感检测详情

| 节点名称（关键字） | 描述                                  | 类型     | 必选 |
| :--------------- | :-------------------------------------| :------  | :--- |
| hitFlag          | 敏感等级，1:正常，2:疑似，3:敏感。      | Integer  | 是   |
| num              | 检测到确认敏感的分片数                  | Integer  | 是   |
| possibleNum      | 检测到疑似敏感的分片数                  | Integer  | 是   |
| label            | 命中的关键字                           | String   | 是   |

