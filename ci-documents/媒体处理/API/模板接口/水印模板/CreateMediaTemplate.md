## 功能描述
CreateMediaTemplate 用于新增水印模板。

## 请求
### 请求实例

```shell
POST /template HTTP/1.1
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
   <Tag>Watermark</Tag>
   <Name>TemplateName</Name>
   <Watermark>
      <Type>Text</Type>
      <LocMode>Absolute</LocMode>
      <Dx>128</Dx>
      <Dy>128</Dy>
      <Pos>TopRight</Pos>
      <StartTime>0</StartTime>
      <EndTime>100.5</EndTime>
      <Text>
        <Text>水印内容</Text>
        <FontSize>30</FontSize>
        <FontType></FontType>
        <FontColor>0xRRGGBB</FontColor>
        <Transparency>30</Transparency>
      </Text>
   </Watermark>
</Request>

<Request>
   <Tag>Watermark</Tag>
   <Name>TemplateName</Name>
   <Watermark>
      <Type>Image</Type>
      <LocMode>Absolute</LocMode>
      <Dx>128</Dx>
      <Dy>128</Dy>
      <Pos>TopRight</Pos>
      <StartTime>0</StartTime>
      <EndTime>100.5</EndTime>
      <Image>
        <Url>http://bucket-1250000000.ci.ap-beijing.myqcloud.com/shuiyin_2.png</Url>
        <Mode>Proportion</Mode>
        <Width>10</Width>
        <Height></Height>
        <Transparency>100</Transparency>
      </Image>
   </Watermark>
</Request>

```

具体数据描述如下：

| 节点名称（关键字） | 父节点 | 描述           | 类型      |
| :----------------- | :----- | :------------- | :-------- |
| Response           | 无     | 保存结果的容器 | Container |


Container 类型 Request 的具体数据描述如下：

| 节点名称（关键字） | 父节点  | 描述                                                     | 类型      | 必选 |
| ------------------ | ------- | -------------------------------------------------------- | --------- | ---- |
| Tag                | Request | 模板类型: Watermark                                   | String    | 是   |
| Name               | Request | 模板名称 仅支持中文、英文、数字、_、-和*                                             | String    | 是   |
| Watermark           | Request| 水印信息                                              | Container | 是   |


Container 类型 Watermark 的具体数据描述如下：

| 节点名称（关键字）     | 父节点  | 描述                                                     | 类型      | 必选 | 默认值       | 限制  |
| ------------------  | ------- | -------------------------------------------------------- | --------- | ---- |---| ---- |
| Type                | Request.Watermark | 水印类型    | String    | 是   | 无  | 1. Text: 文字水印、 Image: 图片水印 |
| Pos                 | Request.Watermark | 基准位置    | String    | 是   | 无  | 1. TopRight、TopLeft、BottomRight、 BottomLeft |
| LocMode             | Request.Watermark | 偏移方式    | String    | 是   | 无  | 1. Relativity: 按比例、 Absolute: 固定位置 |
| Dx                  | Request.Watermark | 水平偏移    | String    | 是   | 无  | 1. 在图片水印中，如果Background为true，当locMode为Relativity时，为% 取值范围[-300 0]；当locMode为Absolute时，为px 值范围：[-4096 0] <br/> 2. 在图片水印中，如果Background为false，当locMode为Relativity时，为% 取值范围[0 100]；当locMode为Absolute时，为px 值范围：[0 4096]<br/>3. 在文字水印中，当locMode为Relativity时，为% 取值范围[0 100]；当locMode为Absolute时，为px 值范围：[0 4096] |
| Dy                  | Request.Watermark | 垂直偏移    | String    | 是   | 无  | 1. 在图片水印中，如果Background为true，当locMode为Relativity时，为% 取值范围[-300 0]；当locMode为Absolute时，为px 值范围：[-4096 0] <br/> 2. 在图片水印中，如果Background为false，当locMode为Relativity时，为% 取值范围[0 100]；当locMode为Absolute时，为px 值范围：[0 4096]<br/>3. 在文字水印中，当locMode为Relativity时，为% 取值范围[0 100]；当locMode为Absolute时，为px 值范围：[0 4096] |
| StartTime           | Request.Watermark | 水印开始时间 | String    | 否   | 0   | 1. [0 视频时长] <br/> 2. 单位为秒 <br/> 3. 支持float格式，执行精度精确到毫秒 |
| EndTime             | Request.Watermark | 水印结束时间 | String    | 否   | 视频结束时间  | 1. [0 视频时长] <br/> 2. 单位为秒 <br/> 3. 支持float格式，执行精度精确到毫秒 |
| Image               | Request.Watermark | 图片水印节点 | Container    | 否   | 无  | 无 |
| Text                | Request.Watermark | 文本水印节点 | Container    | 否   | 无  | 无 |


Container 类型 Image 的具体数据描述如下：

| 节点名称（关键字）     | 父节点  | 描述                                                     | 类型      | 必选 | 默认值       | 限制  |
| ------------------  | ------- | -------------------------------------------------------- | --------- | ---- |---| ---- |
| Url                 | Request.Watermark.Image | 水印图地址(需要Urlencode后传入)   | String    | 是   | 无  | 1. 同bucket的水印图片地址 |
| Mode                 | Request.Watermark.Image | 尺寸模式    | String    | 是   | 无   | 1. Original: 原有尺寸 <br/>  2. Proportion: 按比例 <br/> 3. Fixed: 固定大小 |
| Width                | Request.Watermark.Image | 宽         | String    | 否   | 无   | 1. 当Mode为Original，水印图宽 <br/> 2. 当mode为Proportion，单位为%，背景图：[100 300]；前景图：[1 100]，相对于视频宽，最大不超过4096px<br/> 3. 当mode为Fixed，单位为px，取值范围：[8，4096]<br/> 4.若只设置Width时，按照水印图比例计算Height<br/> |
| Height               | Request.Watermark.Image | 高         | String    | 否   | 无   | 1. 当Mode为Original，水印图高 <br/> 2. 当mode为Proportion，单位为%，背景图：[100 300]；前景图：[1 100]，相对于视频高，最大不超过4096px<br/> 3. 当mode为Fixed，单位为px，取值范围：[8，4096]<br/> 4.若只设置Height时，按照水印图比例计算Width<br/>|
| Transparency         | Request.Watermark.Image | 透明度      | String    | 是   | 无   | 1. 值范围：[1 100]，单位% |
| Background           | Request.Watermark.Image | 是否背景图   | String    | 否   | false   | 1. true、false |

水印位置说明：
![image.png](/uploads/CACE625B9A1C43A5A1F487739DD8E2B7/image.png)

Container 类型 Text 的具体数据描述如下：

| 节点名称（关键字）     | 父节点  | 描述                                                     | 类型      | 必选 | 默认值       | 限制  |
| ------------------  | ------- | -------------------------------------------------------- | --------- | ---- |---| ---- |
| FontSize            | Request.Watermark.Text | 字体大小    | String    | 是   | 无  | 1. 值范围：[5 100]，单位px |
| FontType            | Request.Watermark.Text | 字体类型    | String    | 是   | 无  | 1. 参考下表  |
| FontColor           | Request.Watermark.Text | 字体颜色    | String    | 是   | 无  | 1. 格式：0xRRGGBB |
| Transparency        | Request.Watermark.Text | 透明度      | String    | 是   | 无  | 1. 值范围：[1 100]，单位%|
| Text                | Request.Watermark.Text | 水印内容    | String    | 是   | 无  | 1. 长度不超过64个字符，仅支持中文、英文、数字、_、-和*|



Text 的FontType具体数据描述如下：

| 字体名称               | 支持的语言             | 描述
| ------------------     | -------                | ------
| simfang.ttf            |  中/英                 | 仿宋
| simhei.ttf             |  中/英                 | 黑体
| simkai.ttf             |  中/英                 | 楷体
| simsun.ttc             |  中/英                 | 宋体
| STHeiti-Light.ttc      |  中/英                 | 华文黑体
| STHeiti-Medium.ttc     |  中/英                 | 华文黑体中
| youyuan.TTF            |  中/英                 | 幼圆
| ariblk.ttf             |  英                    | 无
| arial.ttf              |  英                    | 无
| ahronbd.ttf            |  英                    | 无
| Helvetica.dfont        |  英                    | 无
| HelveticaNeue.dfont    |  英                    | 无


## 响应
### 响应头

#### 公共响应头
该响应包含公共响应头，了解公共响应头详情请参阅 [公共响应头部]( https://cloud.tencent.com/document/product/460/42866) 文档。
#### 特有响应头
该响应无特殊的响应头。

### 响应体
该响应体返回为 **application/xml** 数据，包含完整节点数据的内容展示如下：

```shell
<Response>
    <Template>
        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
        <Tag>Watermark</Tag>
        <Name>TemplateName</Name>
        <Watermark>
            <Type>Text</Type>
            <LocMode>Absolute</LocMode>
            <Dx>128</Dx>
            <Dy>128</Dy>
            <Pos>TopRight</Pos>
            <StartTime>0</StartTime>
            <EndTime>100.5</EndTime>
            <Text>
                <Text>水印内容</Text>
                <FontSize>30</FontSize>
                <FontType></FontType>
                <FontColor>0xRRGGBB</FontColor>
                <Transparency>30</Transparency>
            </Text>
        </Watermark>
        <CreateTime>2020-08-05T11:35:24+0800</CreateTime>
        <UpdateTime>2020-08-31T16:15:20+0800</UpdateTime>
    </Template>
</Response>
```

具体的数据内容如下：

| 节点名称（关键字） | 父节点 | 描述                                                   | 类型      |
| :----------------- | :----- | :----------------------------------------------------- | :-------- |
| Response           | 无     | 保存结果的容器 | Container |


Container 节点 Response 的内容：

| 节点名称（关键字） | 父节点   | 描述                           | 类型      |
| :----------------- | :------- | :----------------------------- | :-------- |
| TemplateId          | Response | 模板ID                   | String    |
| Watermark           | Response| 水印信息，详情请见同页面请求体 Watermark 的具体数据描述 | Container |




### 错误码

该请求无特有错误信息，常见的错误信息请参阅 [错误码](https://cloud.tencent.com/document/product/460/42867) 文档。

## 实际案例

### 请求1-文本水印

```shell
POST /template HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 1666
Content-Type: application/xml

<Request>
   <Tag>Watermark</Tag>
   <Name>TemplateName</Name>
   <Watermark>
      <Type>Text</Type>
      <LocMode>Absolute</LocMode>
      <Dx>128</Dx>
      <Dy>128</Dy>
      <Pos>TopRight</Pos>
      <StartTime>0</StartTime>
      <EndTime>100.5</EndTime>
      <Text>
        <Text>水印内容</Text>
        <FontSize>30</FontSize>
        <FontType></FontType>
        <FontColor>0xRRGGBB</FontColor>
        <Transparency>30</Transparency>
      </Text>
   </Watermark>
</Request>
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
    <Template>
        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
        <Tag>Watermark</Tag>
        <Name>TemplateName</Name>
        <Watermark>
            <Type>Text</Type>
            <LocMode>Absolute</LocMode>
            <Dx>128</Dx>
            <Dy>128</Dy>
            <Pos>TopRight</Pos>
            <StartTime>0</StartTime>
            <EndTime>100.5</EndTime>
            <Text>
                <Text>水印内容</Text>
                <FontSize>30</FontSize>
                <FontType></FontType>
                <FontColor>0xRRGGBB</FontColor>
                <Transparency>30</Transparency>
            </Text>
        </Watermark>
        <CreateTime>2020-08-05T11:35:24+0800</CreateTime>
        <UpdateTime>2020-08-31T16:15:20+0800</UpdateTime>
   </Template>
</Response>
```

### 请求2-图片水印

```shell
POST /template HTTP/1.1
Authorization:q-sign-algorithm=sha1&q-ak=AKIDZfbOAo7cllgPvF9cXFrJD0**********&q-sign-time=1497530202;1497610202&q-key-time=1497530202;1497610202&q-header-list=&q-url-param-list=&q-signature=28e9a4986df11bed0255e97ff90500557e0ea057
Host:bucket-1250000000.ci.ap-beijing.myqcloud.com
Content-Length: 1666
Content-Type: application/xml

<Request>
   <Tag>Watermark</Tag>
   <Name>TemplateName</Name>
   <Watermark>
      <Type>Image</Type>
      <LocMode>Absolute</LocMode>
      <Dx>128</Dx>
      <Dy>128</Dy>
      <Pos>TopRight</Pos>
      <StartTime>0</StartTime>
      <EndTime>100.5</EndTime>
      <Image>
        <Url>http://bucket-1250000000.ci.ap-beijing.myqcloud.com/shuiyin_2.png</Url>
        <Mode>Proportion</Mode>
        <Width>10</Width>
        <Height>10</Height>
        <Transparency>30</Transparency>
      </Image>
   </Watermark>
</Request>
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
    <Template>
        <TemplateId>t1460606b9752148c4ab182f55163ba7cd</TemplateId>
        <Tag>Watermark</Tag>
        <Name>TemplateName</Name>
        <Watermark>
            <Type>Image</Type>
            <LocMode>Absolute</LocMode>
            <Dx>128</Dx>
            <Dy>128</Dy>
            <Pos>TopRight</Pos>
            <StartTime>0</StartTime>
            <EndTime>100.5</EndTime>
            <Image>
                <Url>http://bucket-1250000000.ci.ap-beijing.myqcloud.com/shuiyin_2.png</Url>
                <Mode>Proportion</Mode>
                <Width>10</Width>
                <Height>10</Height>
                <Transparency>30</Transparency>
            </Image>
        </Watermark>
        <CreateTime>2020-08-05T11:35:24+0800</CreateTime>
        <UpdateTime>2020-08-31T16:15:20+0800</UpdateTime>
    </Template>
</Response>
```
