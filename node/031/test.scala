
object HelloWorld {

    def add1(args: Int*): Int = {
        var result: Int = 0

        for (arg <- args) {
            result += arg
        }

        return result
    }


    def main(args: Array[String]) = {
        
        val multiply = (a: Int)(b: Int) => a * b

        println(multiply(2)(3))
    }
}