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
    public List<Integer> postorderTraversal(TreeNode root) {
        var res = new ArrayList<Integer>();
        var stk = new Stack<TreeNode>();
        TreeNode visited = null;
        while(!stk.empty() || root!=null)
        {
            while(root!=null)
            {
                stk.push(root);
                root = root.left;
            }
            root = stk.peek();
            stk.pop();
            if(root.right == null || root.right == visited)
            {
                res.add(root.val);
                visited = root;
                root = null;
            }
            else
            {
                stk.push(root);
                root = root.right;
            }
        }
        return res;
    }
}

// class Solution {
//     public List<Integer> postorderTraversal(TreeNode root) {
//         var res = new ArrayList<Integer>();
//         traverse(res,root);
//         return res;
//     }
//     public void traverse(List<Integer> res, TreeNode root)
//     {
//         if(root==null)
//             return;
//         traverse(res,root.left);
//         traverse(res,root.right);
//         res.add(root.val);
//     }
// }
