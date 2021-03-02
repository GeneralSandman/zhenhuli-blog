## 功能概述
数据万象的图片处理 API 能够对图片进行相应处理操作，并返回处理结果。
图片处理请求包属于 GET 请求，请求时需要携带签名。

## 请求语法

```shell
GET /?ci-process=image-process&detect-url=<detect-url>&process-rule=<process-rule> HTTP/1.1
Host: <BucketName-APPID>.cos.<Region>.myqcloud.com
Date: GMT Date
Authorization: Auth String
```


>?Authorization:Auth String （详情请参见 [请求签名](https://cloud.tencent.com/document/product/436/7778) 文档）。

## 请求内容



| 参数名称    | 类型   | 是否必选 | 描述                |
| :---------- | :----- | :--- | :------------------ |
| detect-url | 待处理图片url，需要进行urlencode | String | 是 |
| process-rule | 图片处理规则，详见万象文档 | String | 是 |

## 返回内容

响应包体具体数据内容如下：

| 参数名称          | 类型      | 描述             |
| :---------------- | :-------- | :--------------- |
| ProcessResults | Container | 图片处理结果 |

ProcessResults 节点内容：

| 参数名称 | 类型      | 描述     |
| :------- | :-------- | :------- |
| Object    | Container | 图片处理详细结果 |

Object信息中包含如下内容：

| 参数名称   | 类型   | 描述    |
| :--------- | :----- | :-------|
| Format | String | 图片格式 |
| Width | Int | 图片宽度 |
| Height | Int | 图片高度 |
| Size | Int | 图片大小 |
| Quality | Int | 图片质量 |
| ResultImage | String | 处理后的图片 base64 数据 |

## 示例

#### 请求

```shell
GET /?ci-process=image-process&detect-url=xxx&process-rule=imageMogr2/thumbnail/1000x1000 HTTP/1.1
Host: examplebucket-1250000000.cos.ap-chengdu.myqcloud.com
Date: Tue, 03 Apr 2019 09:06:15 GMT
Authorization:XXXXXXXXXXXX
```

#### 响应

```shell
HTTP/1.1 200 OK
Content-Type: application/xml
Content-Length: 68745
Date: Tue, 03 Apr 2018 09:06:16 GMT
Status: 200 OK
x-cos-request-id: NWFjMzQ0MDZfOTBmYTUwXzZkZV8z****

<ProcessResults>
	<Object>
		<Format>JPEG</Format>
		<Width>700</Width>
		<Height>1047</Height>
		<Size>150297</Size>
		<Quality>90</Quality>
		<ResultImage>xxxxx</ResultImage>
	</Object>
</ProcessResults>
```