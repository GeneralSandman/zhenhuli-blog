# job 接口
## 任务管理
#### 1.提交文档预览任务
> 请求方式类似  https://cloud.tencent.com/document/product/460/38936 

* 接口地址

```
<BucketName-APPID>.ci.<Region>.myqcloud.com/doc_jobs
```

* 请求方式

```
POST
```

* 请求示例

```
POST /doc_jobs HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String

<body>
```

* 请求体 

```
<Request>
  <Tag></Tag>
  <Input>
    <Object></Object>
  </Input>
  <Operation>
    <Output>
      <Region></Region>
      <Bucket></Bucket>
      <Object></Object>
    </Output>
    <DocProcess>
       <StartPage>1</StartPage>
       <EndPage>-1</EndPage>
       <TgtType>png</TgtType>
    </DocProcess>
  </Operation>
  <QueueId></QueueId>
</Request>
```

* 请求参数

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| Tag    | string    | 请求任务的类型 创建任务的类型 默认传 DocProcess  |
| Input    | object    | 文件预览输入对象  | 
| Operation    | object    | 文件预览操作详细参数   |
| QueueId    | string    | 要放入的任务队列id  |

* input对象的参数详情

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| Object    | string    | 预览文件在bucket中存储的位置  |


* Operation对象的参数详情

| 参数名  | 类型   | 是否必填  |含义     |
| ------- | ------ | -------- |-------- |
| DocProcess    | obj    | 否 |文件预览任务，当Tag为DocProcess有效 ，暂时不支持excel文件预览|
| Output    | string    | 文件预览生成文件的输入地址  | 文件预览任务，当Tag为DocProcess有效 其中必须包含${Number}或者${Page}  |

* DocProcess对象的参数详情

| 参数名  | 类型   | 是否必填  |  含义 |
| ------- | ------ | -------- | -------- |
| SrcType| string| 否 |源数据的后缀类型，当前文档转换根据 cos 对象的后缀名来确定源数据类型，当 cos 对象没有后缀名时，可以设置该值 详情请访问：https://cloud.tencent.com/document/product/460/44540|
| TgtType| string| 否 |	png，转成 png 格式的图片文件；jpg，转成 jpg 格式的图片文件；pdf，转成 pdf 格式的文件；如果传入的格式未能识别，默认使用jpg格式|
| StartPage|int| 否 |从第 x 页开始转换，默认为1|
| EndPage|int|否|转换至第 x 页，默认为-1，如果需要转换全部页，设置为-1|
| ImageParams| String | 否 |在线预览生成的图片文件处理参数。|
| TgtFilePrefix|String| 否 |转换后的文件名称前缀，在目标类型为jpg, png时生效，可以是英文，数字，横划线，下划线，长度不超过256个字符，参考[自定义目标文件名称](https://help.aliyun.com/document_detail/72044.html?spm=a2c4g.11186623.6.614.72d611a3YO9Lbm#customfilenames)暂不支持|
| TgtFileSuffix|String| 否 |转换后的文件名称后缀，若值为'def'时使用文件默认的后缀。在目标类型为jpg, png时生效，可以是英文，数字，横划线，下划线，长度不超过256个字符，参考[自定义目标文件名称](https://help.aliyun.com/document_detail/72044.html?spm=a2c4g.11186623.6.614.72d611a3YO9Lbm#customfilenames) 暂不支持|
| Hidecomments|String| 否 |word转换成jpg, png 时，是否隐藏批注和应用修订，默认为 false。true：隐藏批注，false：显示批注和修订 暂不支持|
| PaperDirection|int| 否 |纸张方向，0代表垂直方向，非0代表水平方向 该参数仅用于excel文件|
| PaperSize|int| 否 |纸张大小，0代表A4，1代表A2，2代表A0 该参数仅用于仅用于excel文件|
| Comments|int| 否 | 是否展示文档注释 1代表展示 0 代表不展示  默认值为1 |
| DocPassword|string| 否 | 预览文档的密码|
| Quality|int| 否 | 生成预览图的图片质量 取值范围 [1-100] 默认值100 例:值为100 代表生成图片质量为100%|
| Zoom|int| 否 | 预览图片的缩放参数  取值范围[10-300] 默认值100 例:值为300 代表图片缩放比例为300% 即放大三倍|
ImageParams的参数详情 请参考https://cloud.tencent.com/document/product/460/36540

1.通用参数

| 参数名  | 类型   | 是否必填  |  含义 |
| ------- | ------ | -------- | -------- |
|w| String | 否 |缩图，支持以下两个参数w和h，默认按长边缩放。例 w=指定像素|
|h| String | 否 |缩图，支持以下两个参数w和h，默认按长边缩放。例 h=指定像素|
|format| String | 否 |格式转换 目标图片格式可为：jpg，png，webp。 例 format=jpg|
|Watermark| String | 否 |水印操作，支持image、text两个枚举值，image代表图片水印，text代表文字水印。 例 Watermark=image 参数详情需参考 https://cloud.tencent.com/document/product/460/6930#1 |

2.图片水印相关参数

| 参数名  | 类型   | 是否必填  |  含义 |
| ------- | ------ | -------- | -------- |
|gravity| String | 否 |水印位置。 例 gravity=SouthEast 传参需参九宫图https://cloud.tencent.com/document/product/460/6951#1|
|dx| String | 否 |水平（横轴）边距，单位为像素，缺省值为0|
|dy| String | 否 |垂直（纵轴）边距，单位为像素，缺省值为0|
|image| String | 否 |水印图片地址，需要经过 URL 安全的 Base64 编码。例如，水印图片为 http://examplebucket-1250000000.cos.ap-shanghai.myqcloud.com/shuiyin_2.png，则该处编码后的字符串为aHR0cCUzQS8vZXhhbXBsZWJ1Y2tldC0xMjUwMDAwMDAwLnBpY3NoLm15cWNsb3VkLmNvbS9zaHVpeWluXzIucG5n|

3.文字水印相关参数
 
| 参数名  | 类型   | 是否必填  |  含义 |
| ------- | ------ | -------- | -------- |
|text| String | 否 |需要经过 URL 安全的 Base64 编码|
|font| String | 否 |需要经过 URL 安全的 Base64 编码，默认值 tahoma.ttf 。水印字体列表参考 支持字体列表 https://cloud.tencent.com/document/product/460/19568|
|fontsize| String | 否 |水印文字字体大小，单位为磅，缺省值13|
|fill| String | 否 |字体颜色，缺省为灰色，需设置为十六进制 RGB 格式（如 #FF0000），详情参考 RGB 编码表 https://www.rapidtables.com/web/color/RGB_Color.html，需经过 URL 安全的 Base64 编码，默认值为 #3D3D3D|
|dissolve| String | 否 |文字透明度，取值1 - 100 ，默认90（完全不透明）|
|batch| String | 否 |平铺水印功能，可将文字水印平铺至整张图片。当 batch 设置为1时，开启平铺水印功能|
|degree| String | 否 |文字水印的旋转角度设置，取值范围为0 - 360，默认0|

例：想要实现预览的图片文件有文字水印并且文字旋转角度为180  参数传入Watermark=text&degree=180

* 返回参数

```
<Response>
        <JobsDetail>
                <Code>Success</Code>
                <CreationTime>CreationTime</CreationTime>
                <EndTime>-</EndTime>
                <Input>
                        <Object>Object</Object>
                </Input>
                <JobId>JobId</JobId>
                <Message/>
                <Operation>
                        <DocProcess>
                                <EndPage>0</EndPage>
                                <HideComments>false</HideComments>
                                <ImageParams/>
                                <MaxSheetCol>0</MaxSheetCol>
                                <MaxSheetCount>0</MaxSheetCount>
                                <MaxSheetRow>0</MaxSheetRow>
                                <SrcType/>
                                <StartPage>0</StartPage>
                                <TgtFilePages/>
                                <TgtFilePrefix/>
                                <TgtFileSuffix/>
                                <TgtType>jpg</TgtType>
                        </DocProcess>
                        <Output>
                                <Bucket>Bucket-AppId</Bucket>
                                <Object>objpath</Object>
                                <Region>Region</Region>
                        </Output>
                </Operation>
                <QueueId>QueueId</QueueId>
                <State>Submitted</State>
                <Tag>DocProcess</Tag>
        </JobsDetail>
</Response>
```

#### 2. 查询文档预览任务

* 接口地址

```
<BucketName-APPID>.ci.<Region>.myqcloud.com/doc_jobs/JobId
```

* 请求方式

```
GET
```

* 请求示例 

```
GET /doc_jobs/JobId HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String
```
* 请求参数

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| JobId    | string    | 要查询的JobId|

* 返回示例
非excel类型任务返回值
```
<Response>
        <JobsDetail>
                <Code>Success</Code>
                <CreationTime>2020-07-16T16:56:33+0800</CreationTime>
                <EndTime>2020-07-16T16:56:35+0800</EndTime>
                <Input>
                        <Object>1.docx</Object>
                </Input>
                <JobId>JobId</JobId>
                <Message/>
                <Operation>
                        <DocProcess>
                                <EndPage>0</EndPage>
                                <HideComments>false</HideComments>
                                <ImageParams/>
                                <MaxSheetCol>0</MaxSheetCol>
                                <MaxSheetCount>0</MaxSheetCount>
                                <MaxSheetRow>0</MaxSheetRow>
                                <SrcType/>
                                <StartPage>0</StartPage>
                                <TgtFilePages/>
                                <TgtFilePrefix/>
                                <TgtFileSuffix/>
                                <TgtType>jpg</TgtType>
                        </DocProcess>
                        <DocProcessResult>
                                <FailCount>0</FailCount>
                                <PageInfo>
                                        <PageNo>1</PageNo>
                                        <TgtUri>tgtUri</TgtUri>
                                </PageInfo>
                                <PageInfo>
                                        <PageNo>2</PageNo>
                                        <TgtUri>tgtUri</TgtUri>
                                </PageInfo>
                                <SuccPageCount>2</SuccPageCount>
                                <TaskId/>
                                <TgtType/>
                                <TotalPageCount>2</TotalPageCount>
                        </DocProcessResult>
                        <Output>
                                <Bucket>Bucket-AppId</Bucket>
                                <Object>path</Object>
                                <Region>Region</Region>
                        </Output>
                </Operation>
                <QueueId>QueueId</QueueId>
                <State>Success</State>
                <Tag>DocProcess</Tag>
        </JobsDetail>
</Response>
```

excel类型任务返回值
```
<Response>
        <JobsDetail>
                <Code>Success</Code>
                <CreationTime>2020-09-28T14:47:06+0800</CreationTime>
                <EndTime>2020-09-28T14:47:08+0800</EndTime>
                <Input>
                        <Object>1.xlsx</Object>
                </Input>
                <JobId>d6ca2a6ec015611eb95c41789273ab63d</JobId>
                <Message/>
                <Operation>
                        <DocProcess>
                                <EndPage>2</EndPage>
                                <ImageParams/>
                                <PaperDirection>0</PaperDirection>
                                <PaperSize>0</PaperSize>
                                <SheetId>2</SheetId>
                                <SrcType/>
                                <StartPage>1</StartPage>
                                <TgtType/>
                        </DocProcess>
                        <DocProcessResult>
                                <FailPageCount>0</FailPageCount>
                                <PageInfo>
                                        <PageNo>2</PageNo>
                                        <TgtUri>mark1/2/test-1.jpg</TgtUri>
                                        <X-SheetPics>2</X-SheetPics>
                                </PageInfo>
                                <PageInfo>
                                        <PageNo>2</PageNo>
                                        <TgtUri>mark1/2/test-2.jpg</TgtUri>
                                        <X-SheetPics>2</X-SheetPics>
                                </PageInfo>
                                <SuccPageCount>2</SuccPageCount>
                                <TaskId/>
                                <TgtType/>
                                <TotalPageCount>2</TotalPageCount>
                                <TotalSheetCount>3</TotalSheetCount>
                        </DocProcessResult>
                        <Output>
                                <Bucket>chengdutest-1251704708</Bucket>
                                <Object>mark1/${SheetID}/test-${Number}.jpg</Object>
                                <Region>ap-chengdu</Region>
                        </Output>
                </Operation>
                <QueueId>p5ca4e360fd86411db7a080af40e4e579</QueueId>
                <State>Success</State>
                <Tag>DocProcess</Tag>
        </JobsDetail>
</Response>
```
* 返回参数

| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| JobsDetail    | object    | job对象|

* JobsDetail 参数说明

| 参数名  | 类型   | 含义  |
| ------- | ------ | -------- |
| Code | string | job请求状态 |
| CreationTime    | string | 开通时间|
| EndTime    | string | 任务处理结束时间|
| Input    | obj | 任务对象在桶中的相对位置 |
| JobId    | string | Job的唯一id |
| Message    | string | 处理后返回的 |
| Operation    | obj | 同提交任务入参信息 任务操作详情参数  |
| QueueId    | string | 队列唯一id |
| State    | string | 任务当前状态 |
| Tag    | string | 任务类型 固定为DocProcess |
#### 3.任务列表查询

* 接口地址

```
<BucketName-APPID>.ci.<Region>.myqcloud.com/doc_jobs?querys
```

* 请求方式

```
GET
```

* 请求示例

```
GET /doc_jobs?querys HTTP/1.1
Host: <BucketName-APPID>.ci.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String
```

* querys对象的参数详情
| 参数名  | 类型   | 含义     |
| ------- | ------ | -------- |
| queueId    | string    | 要查看的job队列id  |
| tag    | string    | 默认传入DocProcess |
| states    | string    | 查看的job状态  All 查看所有状态、Submitted、Running、Deleted 已删除,Success,Failed,Cancel,Pause|
**注意：参数需要转为URL编码 即 host/doc_jobs?querys 中的querys对象需要转为url编码**

* 返回参数

```
<Response>
        <JobsDetail>
                <Code>Success</Code>
                <CreationTime>2020-07-20T10:43:17+0800</CreationTime>
                <EndTime>-</EndTime>
                <Input>
                        <Object>1.docx</Object>
                </Input>
                <JobId>JobId</JobId>
                <Message/>
                <Operation>
                        <DocProcess>
                                <EndPage>1</EndPage>
                                <ImageParams>ImageParams</ImageParams>
                                <SrcType/>
                                <StartPage>1</StartPage>
                                <TgtType>png</TgtType>
                        </DocProcess>
                        <Output>
                                <Bucket>BucketId</Bucket>
                                <Object>file/test-${Page}.jpg</Object>
                                <Region>Region</Region>
                        </Output>
                </Operation>
                <QueueId>QueueId</QueueId>
                <State>Submitted</State>
                <Tag>DocProcess</Tag>
        </JobsDetail>
        <JobsDetail>
                <Code>Success</Code>
                <CreationTime>2020-07-20T10:43:17+0800</CreationTime>
                <EndTime>-</EndTime>
                <Input>
                        <Object>test.docx</Object>
                </Input>
                <JobId>JobId</JobId>
                <Message/>
                <Operation>
                        <DocProcess>
                                <EndPage>1</EndPage>
                                <ImageParams>ImageParams</ImageParams>
                                <SrcType/>
                                <StartPage>1</StartPage>
                                <TgtType>png</TgtType>
                        </DocProcess>
                        <Output>
                                <Bucket>BucketId</Bucket>
                                <Object>file/test-${Page}.jpg</Object>
                                <Region>Region</Region>
                        </Output>
                </Operation>
                <QueueId>QueueId</QueueId>
                <State>Submitted</State>
                <Tag>DocProcess</Tag>
        </JobsDetail>
        <NextToken>19193</NextToken>
</Response>
```