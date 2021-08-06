

# Scala

![](./cover.jpeg)


> [!TIP|style:flat|label:摘要]
> 本文章整理一点在学习Scala时遇到的难点，写点例子分享一下。


Scala 学习教程
https://docs.scala-lang.org/zh-cn/tour/tour-of-scala.html


Scala 在线运行工具

https://scalafiddle.io/


命令行执行 scala 交互式编程






<iframe height="400px" frameborder="0" style="width: 100%" src="https://embed.scalafiddle.io/embed?sfid=FrnBgDQ/0&theme=dark&layout=v50"></iframe>

## 规范

类名 - 对于所有的类名的第一个字母要大写。

方法名称 - 所有的方法名称的第一个字母用小写。


程序文件名 - 程序文件的名称应该与对象名称完全匹配(新版本不需要了，但建议保留这种习惯)。





## 包

import java.awt.Color  // 引入Color
 
import java.awt._  // 引入包内所有成员
 
def handler(evt: event.ActionEvent) { // java.awt.event.ActionEvent
  ...  // 因为引入了java.awt，所以可以省去前面的部分
}

// 引入多个
import java.awt.{Color, Font}
 
// 重命名成员
import java.util.{HashMap => JavaHashMap}
 
// 隐藏成员
import java.util.{HashMap => _, _} // 引入了util包的所有成员，但是HashMap被隐藏了




## 什么是 符号字面量


## 变量类型声明









var VariableName : DataType [=  Initial Value]

或

val VariableName : DataType [=  Initial Value]


var myVar = 10;
val myVal = "Hello, Scala!";


## 类的访问修饰符号



## for


var a = 0;
      var b = 0;
      // for 循环
      for( a <- 1 to 3; b <- 1 to 3){
         println( "Value of a: " + a + ",Value of b: " + b );
      }


      for( a <- 1 to 3){
          for (b <- 1 to 3) {
         println( "Value of a: " + a + ",Value of b: " + b );
          }
      }




var a = 0;
      val numList = List(1,2,3,4,5,6);

      // for 循环
      for( a <- numList ){
         println( "Value of a: " + a );
      }



      var a = 0;
      val numList = List(1,2,3,4,5,6,7,8,9,10);

      // for 循环
      for( a <- numList
           if a != 3; if a < 8 ){
         println( "Value of a: " + a );
      }