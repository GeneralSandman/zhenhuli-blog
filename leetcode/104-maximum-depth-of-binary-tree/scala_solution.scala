class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
  var value: Int = _value
  var left: TreeNode = _left
  var right: TreeNode = _right
}

object Solution {
    def maxDepth(root: TreeNode): Int = {
       if (root == null)
         return 0
      return scala.math.max(maxDepth(root.left), maxDepth(root.right)) + 1
    }




    def main(args: Array[String]) {
       val a = new TreeNode(0)
       val b = new TreeNode(1, a)
       val root = new TreeNode(1, b)

       println(maxDepth(root))
   }
}