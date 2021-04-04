object HelloWorld {
   /* 这是我的第一个 Scala 程序
    * 以下程序将输出'Hello World!' 
    */
   def main(args: Array[String]) {
      println("Hello, world!\n\n") // 输出 Hello World
      test4()
   }

   def test5() {
       var a = 0;
       var array = List(1,2,3,4,5,6,7,8,9,10)

       var result = for{a<-array
            if a!=3;if a<8}yield

        for (a<-result) {
            println(a)
        }
   }

   def test4() {
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
   }

   def test3() {
       var a = 0
       for (a <- 0 to 10) {
           println(a)
       }

       for (a <- 0 until 10) {
           println(a)
       }

       for (a <- 0 to 10 by 3) {
           println(a)
       }
   }

   def test() {
       var str : String = "zhenhuli"
       val stl : String = "zhenhuli"

       str = "1234"
   }

   def test2() {
        var x = 10;

      if( x < 20 ){
         println("x < 20");
      } else {
          println("x > 20")
      }
   }

}