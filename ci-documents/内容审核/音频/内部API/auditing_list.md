## 功能描述
音频的审核记录查询


## 请求

### 请求示例

```shell
GET /audio/records HTTP/1.1
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
| scene              | 无     | 审核场景 All、Porn、Terrorism、Politics         | String  | 是   |
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

``` shell
{
    "code": 0,
    "message": "",
    "data": {
        "records": [{
            "recordID": "",
            "bucketID": "",
            "object": "",
            "createTime": "",
            "state": "",
            "freeze": "",
            "score": 99,
            "hitFlag": 3,
            "label": "",
            "type": 2,
        }]
    }
}
```

| 节点名称（关键字） | 描述                                             | 类型    | 必选 |
| :----------------- | :----------------------------------------------- | :------ | :--- |
| region             | 该记录的uid                                      | String  | 是   |
| bucketID           | bucket桶                                         | String  | 是   |
| object             | 文件全路径名字                                   | String  | 是   |
| createTime         | 该文件的审核时间                                 | String  | 是   |
| freeze             | 冻结状态。2:已冻结，3:未冻结。                   | String  | 是   |
| score              | 敏感分值。                                       | String  | 是   |
| type               | 命中的敏感类型，0:正常，1:涉黄，3:涉恐，4:涉政。 | Integer | 是   |
| hitFlag            | 敏感等级，1:正常，2:疑似，3:敏感。               | Integer | 是   |
| state              | 客户判定结果，1:正常。                           | String  | 否   |
| label              | 敏感标签                                         | String  | 否   |

