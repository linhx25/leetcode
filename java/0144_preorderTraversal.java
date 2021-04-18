/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// 非递归
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        var res = new ArrayList<Integer>();
        var stk = new Stack<TreeNode>();
        while(!stk.empty() || root!=null)
        {
            while(root!=null)
            {
                res.add(root.val);
                stk.push(root);
                root = root.left;
            }
            root = stk.peek().right;
            stk.pop();
        }
        return res;
    }
}

//  前序遍历：根左右
// class Solution {
//     public List<Integer> preorderTraversal(TreeNode root) {
//         var res = new ArrayList<Integer>();
//         traverse(res,root);
//         return res;
//     }
//     public void traverse(List<Integer> res, TreeNode root)
//     {
//         if(root==null)
//             return;
//         res.add(root.val);
//         traverse(res,root.left);
//         traverse(res,root.right);
//     }
// }
