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
    public int sumNumbers(TreeNode root) {
        int res = traverse(root,new TreeNode());
        return res;
    }
    public int traverse(TreeNode root,TreeNode parent)
    {
        if(root==null)
            return 0;
        root.val += parent.val*10;
        if(root.left==null && root.right==null)
            return root.val;
        else
            return traverse(root.left,root)+traverse(root.right,root);
    }
}
