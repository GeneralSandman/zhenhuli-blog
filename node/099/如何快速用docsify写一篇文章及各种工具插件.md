

# 如何快速用docsify写一篇文章及各种工具插件

![]()
![]()
![]()

```plantuml
@startuml

skinparam responseMessageBelowArrow true

actor User #red

queue       DataBase       as DataBase

User -> Billing

User -> NSQD:   1.0 TCP Connect
User -> NSQD:   1.1 Send MagicV2
User -> NSQD:   1.2 Send Cmd:IDENTIFY
NSQD --> User:  1.3 OK
User -> NSQD:   1.4 Send Cmd:SUB
User -> NSQD:   1.5 Send Cmd:RDY
NSQD --> User:  1.6 OK
User -> NSQD:  1.7 Send Cmd:NOP 
NSQD --> User:	1.7 _heartbeat_
User -> NSQD:  1.8 Send Cmd:NOP _heartbeat_
NSQD --> User:	1.8 _heartbeat_


Producer -> NSQD: 	2.0 TCP Connect
Producer -> NSQD:	2.1 Send MagicV2
Producer -> NSQD:	2.2 Send Cmd:IDENTIFY
NSQD --> Producer:  2.3 OK
NSQD --> Producer:  2.4 Send Cmd:NOP _heartbeat_
NSQD --> Producer:  2.5 Send Cmd:NOP _heartbeat_
NSQD --> Producer:  2.6 Send Cmd:NOP _heartbeat_
Producer -> NSQD:	2.7 Send Cmd:PUB
NSQD --> Producer:  2.8 OK


NSQD --> User:  3.1 Send Nsq-Message
User -> NSQD:   3.2 Send Cmd:FIN

Producer -> NSQD:	2.9 Send Cmd:PUB
NSQD --> Producer:  2.10 OK

NSQD --> User:  3.3 Send Nsq-Message
User -> NSQD:   3.4 Send Cmd:FIN


@enduml
```


> [!TIP|style:flat|label:引用头]
> 引用body1
> 
> In addition, this alert uses an own heading and hides specific icon.
> 
> 123132

> [!NOTE|style:flat]
> An alert of type 'note' using global style 'callout'.

> [!NOTE|style:callout]
> An alert of type 'note' using global style 'callout'.


> [!TIP|style:flat]
> An alert of type 'tip' using global style 'callout'.

> [!TIP|style:callout]
> An alert of type 'tip' using global style 'callout'.


> [!WARNING|style:flat]
> An alert of type 'warning' using global style 'callout'.

> [!WARNING|style:callout]
> An alert of type 'warning' using global style 'callout'.


> [!ATTENTION|style:flat]
> An alert of type 'attention' using global style 'callout'.

> [!ATTENTION|style:callout]
> An alert of type 'attention' using global style 'callout'.

https://plantuml.com/zh/


### Section X
```plantuml
@startuml
Alice -> Bob: Authentication Request
Bob --> Alice: Authentication Response

Alice -> Bob: Another authentication Request
Alice <-- Bob: another authentication Response
@enduml
```



# Example

# Basic 1
```plantuml
:一级: -right-*  :二级: 
:二级: -right-*  :三级: 
:三级: -right-*  :一级:

:一级: -right-*  :三级: 
:三级: -right-*  :二级: 
:二级: -right-*  :一级:
```

## Basic 2
```plantuml
@startuml
autonumber

Alice -> Bob: Authentication Request
Bob --> Alice: Authentication Response

Alice -> Bob: Another authentication Request
Alice <-- Bob: another authentication Response
@enduml
```





```plantuml

@startuml
:foo1;
-> You can put text on arrows;
if (test) then
  -[#blue]->
  :foo2;
  -[#green,dashed]-> The text can
  also be on several lines
  and **very** long...;
  :foo3;
else
  -[#black,dotted]->
  :foo4;
endif
-[#gray,bold]->
:foo5;
@enduml
```


<details>
用于折叠信息
</details>





