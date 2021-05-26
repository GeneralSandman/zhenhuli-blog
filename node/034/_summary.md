消息队列 CMQ 支持 Pull（队列） 和 Push（主题） 两种方式：

Push 模型：当 Producer 发出的消息到达后，服务端马上将这条消息投递给 Consumer。

Pull 模型：当服务端收到这条消息后什么也不做，只是等着 Consumer 主动到自己这里来读，即 Consumer 这里有一个“拉取”的动作。

本文将结合不同场景，简要分析 Push 模型和 Pull 模型各自存在的利弊。