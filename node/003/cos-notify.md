# cos回调


# agent

通过路由选择worker，目前有三种处理逻辑：AgentWorker,AgentBatchWorker,RuleWorker

收到的消息格式都相同：
agent收到消息，消息格式前四个字符来路由worker，后边的5-12字符为 size cmd，13个字符之后pb格式消息

## AgentWorker AgentBatchWorker 逻辑、代码基本相同

；
处理消息，生成task,task 格式为 qcnf<NotifyType><body-length><body>, 其中body的格式为pb；写入CMQ，

## RuleWorker

处理消息：

如果cmd 是 NotifyType_RULES_UPDATE

## Timer 每分钟从mysql中读入匹配规则







------------



# server

# agent

通过路由选择worker，目前有三种处理逻辑：NotifyWorker, SysRuleWorker, RuleWorker


收到的消息格式都相同：
agent收到消息，消息格式前四个字符来路由worker，后边的5-12字符为 size cmd，13个字符之后pb格式消息

## NotifyWorker


## SysRuleWorker


## RuleWorker


---------------

COS Bucket 上传时、删除文件时运行云函数、应用程序通过 SDK 调用时运行云函数，或指定云函数定期执行。您可以使用云函数作为 COS 服务的数据处理触发程序轻松实现 IFTTT 逻辑，您也可以通过构建灵活的定时自动化任务，用于覆盖手工完成的操作，轻松构建灵活可控的软件架构。





