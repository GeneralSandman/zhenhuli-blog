Tikker是一个面向海量用户规模，提供可靠的事件通知服务的分布式定时器系统。Tikker借鉴云原生的思想，为定时器到期处理任务的管理，提供了一个运行在不可靠的环境下的高可靠、去中心化的任务调度和分发机制。Tikker集成的这个分布式分发任务、调度任务的任务管理模块，帮助tikker规避了传统中心化任务系统存在的调度中心单点、无法平行扩容、突发流量系统不稳定等问题。Tikker自2019年7月上线以来，承接了超过了20个业务的接入，包含QQ提醒、QQ机器人定时消息等，并经受住了2021年春节红包活动高达100w/s qps的压测考验，为QQ春节红包活动提供了可靠的定时器服务。