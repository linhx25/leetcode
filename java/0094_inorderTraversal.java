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
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        var res = new ArrayList<Integer>();
        var stk = new Stack<TreeNode>();
        while(root!=null || !stk.empty())
        {
            while(root!=null)
            {
                stk.push(root);
                root = root.left;
            }
            root = stk.peek();
            res.add(root.val);
            stk.pop();
            root = root.right;
        }
        return res;
    }
}

// // 中序遍历：左根右
// class Solution {
//     public List<Integer> inorderTraversal(TreeNode root) {
//         var res = new ArrayList<Integer>();
//         traverse(res,root);
//         return res;
//     }
//     public void traverse(List<Integer> res, TreeNode root)
//     {
//         if(root==null)
//             return;
//         traverse(res,root.left);
//         res.add(root.val);
//         traverse(res,root.right);
//     }
// }
