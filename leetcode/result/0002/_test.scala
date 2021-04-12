
class ListNode(_x: Int = 0, _next: ListNode = null) {
  var next: ListNode = _next
  var x: Int = _x
}


object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        var result : ListNode = null
        if (l1 == null && l2 == null) {
          return result
        }

        

    }


    def main(args: Array[String]): Unit = {
       val a = new TreeNode(0)
       val b = new TreeNode(1, a)
       val root = new TreeNode(1, b)

       println(maxDepth(root))
   }
}