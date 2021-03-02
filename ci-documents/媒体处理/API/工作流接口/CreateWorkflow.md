## 功能描述
CreateWorkflow 用于新增工作流。

## 请求
### 请求实例

```shell
POST /workflow HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: <GMT Date>
Authorization: <Auth String>
Content-Length: <length>
Content-Type: application/xml

<body>
```

> Authorization: Auth String （详情请查阅 [请求签名](https://cloud.tencent.com/document/product/436/7778) 文档）。

### 请求头
#### 公共头部
该请求操作的实现使用公共请求头，了解公共请求头详情请参阅 [公共请求头部](https://cloud.tencent.com/document/product/460/42865) 文档。
#### 非公共头部
该请求操作无特殊的请求头部信息。

### 请求体
该请求操作的实现需要有如下请求体。

```shell
<Request>
    <MediaWorkflow>
        <Name>demo</Name>
        <Topology>
            <Dependencies>
                <Start>Snapshot_1581665960536,Transcode_1581665960537,Animation_1581665960538,Concat_1581665960539,SmartCover_1581665960539</Start>
                <Snapshot_1581665960536>End</Snapshot_1581665960536>
                <Transcode_1581665960537>End</Transcode_1581665960537>
                <Animation_1581665960538>End</Animation_1581665960538>
                <Concat_1581665960539>End</Concat_1581665960539>
                <SmartCover_1581665960539>End</SmartCover_1581665960539>
            </Dependencies>
            <Nodes>
                <Start>
                    <Type>Start</Type>
                    <Input>
                        <QueueId></QueueId>
                        <ObjectPrefix></ObjectPrefix>
                    </Input>
                </Start>
                <SmartCover_1581665960539>
                    <Type>SmartCover</Type>
                    <Operation>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/cover-${Number}.jpg</Object>
                        </Output>
                    </Operation>
                </SmartCover_1581665960539>
                <Snapshot_1581665960536>
                    <Type>Snapshot</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/snapshot-${number}.${Ext}</Object>
                        </Output>
                    </Operation>
                </Snapshot_1581665960536>
                <Transcode_1581665960537>
                    <Type>Transcode</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/snapshot-${number}.jpg</Object>
                        </Output>
                    </Operation>
                </Transcode_1581665960537>
                <Animation_1581665960538>
                    <Type>Animation</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/bcd.gif</Object>
                        </Output>
                    </Operation>
                </Animation_1581665960538>
                <Concat_1581665960539>
                    <Type>Concat</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/abc.${ext}</Object>
                        </Output>
                    </Operation>
                </Concat_1581665960539>
            </Nodes>
        </Topology>
    </MediaWorkflow>
</Request>

```

具体数据描述如下：

| 节点名称（关键字） | 父节点 | 描述           | 类型      | 必选 |
| ------------------ | ------ | -------------- | --------- | ---- |
| Request            | 无     | 保存请求的容器 | Container | 是   |

Container 类型 Request 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述          | 类型      | 必选 |
| ------------------ | ------- | -------- | --------- | ---- |
| MediaWorkflow      | Request | 工作流节点 | Container    | 是   |


Container 类型 MediaWorkflow 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Name      | Request.MediaWorkflow | 工作流名称 | String    | 是   | 支持中文、英文、数字、—和_，长度限制128字符 |
| Topology  | Request.MediaWorkflow | 拓扑信息 | Container    | 是   | 无 |



Container 类型 Topology 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Dependencies      | Request.MediaWorkflow.Topology | 节点依赖关系 | Container    | 是   | 无 |
| Nodes             | Request.MediaWorkflow.Topology | 节点列表 | Container    | 是   | 无 |

Container 类型 Nodes 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Start         | Request.MediaWorkflow.Topology.Nodes | 开始节点 | Container    | 是   | 只有唯一一个开始节点 |
| Animation_*** | Request.MediaWorkflow.Topology.Nodes | 动图类型节点 | Container    | 是   | 节点名称以Animation为前缀，可能有多个动图节点 |
| Snapshot_***  | Request.MediaWorkflow.Topology.Nodes | 截图类型节点 | Container    | 是   | 节点名称以Snapshot为前缀，可能有多个截图节点|
| SmartCover_*** | Request.MediaWorkflow.Topology.Nodes | 智能封面节点 | Container    | 是   | 节点名称以SmartCover为前缀，可能有多个智能封面节点|
| Transcode_***  | Request.MediaWorkflow.Topology.Nodes | 转码节点 | Container    | 是   | 节点名称以Transcode为前缀，可能有多个转码节点|
| Concat_***  | Request.MediaWorkflow.Topology.Nodes | 音视频拼接节点 | Container    | 是   | 节点名称以Concat为前缀，可能有多个音视频拼接节点|

Container 类型 Start 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Type         | Request.MediaWorkflow.Topology.Nodes.Start | 节点类型 | String    | 是   | Start |
| Input        | Request.MediaWorkflow.Topology.Nodes.Start | 输入信息 | Container | 是   | 无 |

Container 类型 Input 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| ObjectPrefix       | Request.MediaWorkflow.Topology.Nodes.Start.Input | Object前缀 | String    | 是   | 无 |
| QueueId       | Request.MediaWorkflow.Topology.Nodes.Start.Input | 队列ID | String    | 是   | 无 |


Container 类型 Animation_*** 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Type       | Request.MediaWorkflow.Topology.Nodes.Animation_*** | 节点类型 | String    | 是   | Animation |
| Operation  | Request.MediaWorkflow.Topology.Nodes.Animation_*** | 操作规则 | Container | 是   | 无 |

Container 类型 Operation 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| TemplateId   | Request.MediaWorkflow.Topology.Nodes.Animation_***.Operation | 模板ID  | String    | 是   | 无 |
| Output       | Request.MediaWorkflow.Topology.Nodes.Animation_***.Operation | 输出地址 | Container | 是   | 无 |


Container 类型 Output 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Region   | Request.MediaWorkflow.Topology.Nodes.Animation_***.Operation.Output | 存储桶的园区  | String    | 是   | 无 |
| Bucket   | Request.MediaWorkflow.Topology.Nodes.Animation_***.Operation.Output | 存储桶的名称  | String    | 是   | 无 |
| Object   | Request.MediaWorkflow.Topology.Nodes.Animation_***.Operation.Output | 结果文件名称  | String    | 是   |  1、bcd/${RunId}/bcd.gif <br/> 2、bcd/${RunId}/bcd.webp <br/> |

Container 类型 Snapshot_*** 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Type       | Request.MediaWorkflow.Topology.Nodes.Snapshot_****** | 节点类型 | String    | 是   | Snapshot |
| Operation  | Request.MediaWorkflow.Topology.Nodes.Snapshot_****** | 操作规则 | Container | 是   | 无 |

Container 类型 Operation 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| TemplateId   | Request.MediaWorkflow.Topology.Nodes.Snapshot_***.Operation | 模板ID  | String    | 是   | 无 |
| Output       | Request.MediaWorkflow.Topology.Nodes.Snapshot_***.Operation | 输出地址 | Container | 是   | 无 |

Container 类型 Output 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Region   | Request.MediaWorkflow.Topology.Nodes.Snapshot_***.Operation.Output | 存储桶的园区  | String    | 是   | 无 |
| Bucket   | Request.MediaWorkflow.Topology.Nodes.Snapshot_***.Operation.Output | 存储桶的名称  | String    | 是   | 无 |
| Object   | Request.MediaWorkflow.Topology.Nodes.Snapshot_***.Operation.Output | 结果文件名称  | String    | 是   |  1、abc/${RunId}/snapshot-${number}.${Ext} <br/> 2、bcd/${RunId}/snapshot-${number}.jpg <br/> |

Container 类型 SmartCover_*** 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Type       | Request.MediaWorkflow.Topology.Nodes.SmartCover_***| 节点类型 | String    | 是   | SmartCover |
| Operation  | Request.MediaWorkflow.Topology.Nodes.SmartCover_*** | 操作规则 | Container | 是   | 无 |

Container 类型 Operation 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Output       | Request.MediaWorkflow.Topology.Nodes.SmartCover_***.Operation | 输出地址 | Container | 是   | 无 |

Container 类型 Output 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Region   | Request.MediaWorkflow.Topology.Nodes.SmartCover_***.Operation.Output | 存储桶的园区  | String    | 是   | 无 |
| Bucket   | Request.MediaWorkflow.Topology.Nodes.SmartCover_***.Operation.Output | 存储桶的名称  | String    | 是   | 无 |
| Object   | Request.MediaWorkflow.Topology.Nodes.SmartCover_***.Operation.Output | 结果文件名称  | String    | 是   |  1、必须包含 ${Number} ${RunId}参数。<br/> |

Container 类型 Transcode_*** 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Type       | Request.MediaWorkflow.Topology.Nodes.Transcode_*** | 节点类型 | String    | 是   | Transcode |
| Operation  | Request.MediaWorkflow.Topology.Nodes.Transcode_*** | 操作规则 | Container | 是   | 无 |

Container 类型 Operation 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| TemplateId   | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation | 转码模板ID  | String    | 是   | 无 |
| WatermarkTemplateId   | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation | 水印模板ID  | String    | 是   | 可以使用多个水印模板 |
| RemoveWatermark       | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation | 去除水印参数        | Container | 否   |无|
| Output       | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation | 输出地址 | Container | 是   | 无 |

Container 类型 RemoveWatermark 的具体数据描述如下：

| 节点名称（关键字） | 父节点                      | 描述                                   | 类型      | 必选 | 限制|
| ------------------ | :-------------------------- | -------------------------------------- | --------- | ---- | ---- |
| Dx                 | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.RemoveWatermark|  距离左上角原点x偏移, [0, 4096]   | string | 是   | 1. 值范围：[0，4096]<br/>2. 单位：px |
| Dy                 | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.RemoveWatermark |  距离左上角原点y偏移, [0, 4096]   | string | 是   | 1. 值范围：[0，4096]<br/>2. 单位：px |
| Width              | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.RemoveWatermark |  宽, (0, 4096]                 | string | 是   | 1. 值范围：(0，4096]<br/>2. 单位：px |
| Height             | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.RemoveWatermark |  高, (0, 4096]                 | string | 是   | 1. 值范围：(0，4096]<br/>2. 单位：px |

Container 类型 Output 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Region   | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.Output | 存储桶的园区  | String    | 是   | 无 |
| Bucket   | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.Output | 存储桶的名称  | String    | 是   | 无 |
| Object   | Request.MediaWorkflow.Topology.Nodes.Transcode_***.Operation.Output | 结果文件名称  | String    | 是   | 无 |

Container 类型 Concat_*** 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| Type       | Request.MediaWorkflow.Topology.Nodes.Concat_*** | 节点类型 | String    | 是   | Concat |
| Operation  | Request.MediaWorkflow.Topology.Nodes.Concat_*** | 操作规则 | Container | 是   | 无 |


Container 类型 Operation 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述       | 类型      | 必选 | 限制|
| ------------------ | ------- | ------| --------- | ---- | ---- |
| TemplateId   | Request.MediaWorkflow.Topology.Nodes.Concat_***.Operation | 模板ID  | String    | 是   | 无 |
| Output       | Request.MediaWorkflow.Topology.Nodes.Concat_***.Operation | 输出地址 | Container | 是   | 无 |

## 响应

### 响应头

#### 公共响应头
该响应包含公共响应头，了解公共响应头详情请参阅 [公共响应头部]( https://cloud.tencent.com/document/product/460/42866) 文档。
#### 特有响应头
该响应无特殊的响应头。

### 响应体
该响应体返回为 **application/xml** 数据，包含完整节点数据的内容展示如下：

``` shell
<Response>
    <MediaWorkflow>
        <Name>demo</Name>
        <BucketId></BucketId>
        <WorkflowId></WorkflowId>
        <State></State>
        <Topology>
            <Dependencies>
                <Start>Snapshot_1581665960536,Transcode_1581665960537,Animation_1581665960538,Concat_1581665960539,SmartCover_1581665960539</Start>
                <Snapshot_1581665960536>End</Snapshot_1581665960536>
                <Transcode_1581665960537>End</Transcode_1581665960537>
                <Animation_1581665960538>End</Animation_1581665960538>
                <Concat_1581665960539>End</Concat_1581665960539>
                <SmartCover_1581665960539>End</SmartCover_1581665960539>
            </Dependencies>
            <Nodes>
                <Start>
                    <Type>Start</Type>
                    <Input>
                        <QueueId></QueueId>
                        <ObjectPrefix></ObjectPrefix>
                    </Input>
                </Start>
                <SmartCover_1581665960539>
                    <Type>SmartCover</Type>
                    <Operation>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/cover-${Number}.jpg</Object>
                        </Output>
                    </Operation>
                </SmartCover_1581665960539>
                <Snapshot_1581665960536>
                    <Type>Snapshot</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/snapshot-${number}.${Ext}</Object>
                        </Output>
                    </Operation>
                </Snapshot_1581665960536>
                <Transcode_1581665960537>
                    <Type>Transcode</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/snapshot-${number}.jpg</Object>
                        </Output>
                    </Operation>
                </Transcode_1581665960537>
                <Animation_1581665960538>
                    <Type>Animation</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/bcd.gif</Object>
                        </Output>
                    </Operation>
                </Animation_1581665960538>
                <Concat_1581665960539>
                    <Type>Concat</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/abc.${ext}</Object>
                        </Output>
                    </Operation>
                </Concat_1581665960539>
            </Nodes>
        </Topology>
        <CreateTime></CreateTime>
        <UpdateTime></UpdateTime>
    </MediaWorkflow>
</Response>

```

具体的数据内容如下：

| 节点名称（关键字） | 父节点 | 描述                                                   | 类型      |
| :----------------- | :----- | :----------------------------------------------------- | :-------- |
| Response           | 无     | 保存结果的容器，同Describe Workflow中的Response.MediaWorkflowList | Container |


### 错误码
常见的错误信息请参阅 [错误码](https://cloud.tencent.com/document/product/460/42867) 文档。

## 实际案例

### 请求

```shell
POST /workflow HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 166
Content-Type: application/xml

<Request>
    <MediaWorkflow>
        <Name>demo</Name>
        <Topology>
            <Dependencies>
                <Start>Snapshot_1581665960536,Transcode_1581665960537,Animation_1581665960538,Concat_1581665960539,SmartCover_1581665960539</Start>
                <Snapshot_1581665960536>End</Snapshot_1581665960536>
                <Transcode_1581665960537>End</Transcode_1581665960537>
                <Animation_1581665960538>End</Animation_1581665960538>
                <Concat_1581665960539>End</Concat_1581665960539>
                <SmartCover_1581665960539>End</SmartCover_1581665960539>
            </Dependencies>
            <Nodes>
                <Start>
                    <Type>Start</Type>
                    <Input>
                        <QueueId></QueueId>
                        <ObjectPrefix></ObjectPrefix>
                    </Input>
                </Start>
                <SmartCover_1581665960539>
                    <Type>SmartCover</Type>
                    <Operation>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/cover-${Number}.jpg</Object>
                        </Output>
                    </Operation>
                </SmartCover_1581665960539>
                <Snapshot_1581665960536>
                    <Type>Snapshot</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/snapshot-${number}.${Ext}</Object>
                        </Output>
                    </Operation>
                </Snapshot_1581665960536>
                <Transcode_1581665960537>
                    <Type>Transcode</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/snapshot-${number}.jpg</Object>
                        </Output>
                    </Operation>
                </Transcode_1581665960537>
                <Animation_1581665960538>
                    <Type>Animation</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/bcd.gif</Object>
                        </Output>
                    </Operation>
                </Animation_1581665960538>
                <Concat_1581665960539>
                    <Type>Concat</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/abc.${ext}</Object>
                        </Output>
                    </Operation>
                </Concat_1581665960539>
            </Nodes>
        </Topology>
    </MediaWorkflow>
</Request>
```

### 响应

```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 230
Connection: keep-alive
Date: Thu, 15 Jun 2017 12:37:29 GMT
Server: tencent-ci
x-ci-request-id: NTk0MjdmODlfMjQ4OGY3XzYzYzhfMjc=

<Response>
    <MediaWorkflow>
        <Name>demo</Name>
        <State></State>
        <BucketId></BucketId>
        <WorkflowId></WorkflowId>
        <Topology>
            <Dependencies>
                <Start>Snapshot_1581665960536,Transcode_1581665960537,Animation_1581665960538,Concat_1581665960539,SmartCover_1581665960539</Start>
                <Snapshot_1581665960536>End</Snapshot_1581665960536>
                <Transcode_1581665960537>End</Transcode_1581665960537>
                <Animation_1581665960538>End</Animation_1581665960538>
                <Concat_1581665960539>End</Concat_1581665960539>
                <SmartCover_1581665960539>End</SmartCover_1581665960539>
            </Dependencies>
            <Nodes>
                <Start>
                    <Type>Start</Type>
                    <Input>
                        <QueueId></QueueId>
                        <ObjectPrefix></ObjectPrefix>
                    </Input>
                </Start>
                <SmartCover_1581665960539>
                    <Type>SmartCover</Type>
                    <Operation>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/cover-${Number}.jpg</Object>
                        </Output>
                    </Operation>
                </SmartCover_1581665960539>
                <Snapshot_1581665960536>
                    <Type>Snapshot</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/snapshot-${number}.${Ext}</Object>
                        </Output>
                    </Operation>
                </Snapshot_1581665960536>
                <Transcode_1581665960537>
                    <Type>Transcode</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/snapshot-${number}.jpg</Object>
                        </Output>
                    </Operation>
                </Transcode_1581665960537>
                <Animation_1581665960538>
                    <Type>Animation</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>bcd/${RunId}/bcd.gif</Object>
                        </Output>
                    </Operation>
                </Animation_1581665960538>
                <Concat_1581665960539>
                    <Type>Concat</Type>
                    <Operation>
                        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
                        <Output>
                            <Region></Region>
                            <Bucket></Bucket>
                            <Object>abc/${RunId}/abc.${ext}</Object>
                        </Output>
                    </Operation>
                </Concat_1581665960539>
            </Nodes>
        </Topology>
        <CreateTime></CreateTime>
        <UpdateTime></UpdateTime>
    </MediaWorkflow>
</Response>
```
