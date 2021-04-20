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
    public boolean isBalanced(TreeNode root) {
        int[] diff = {0};
        traverse(root,0,diff);
        return diff[0]>1?false:true;
    }
    public int traverse(TreeNode root, int depth, int[] diff)
    {
        if(root==null)
            return 0;
        var left = traverse(root.left,depth+1,diff);
        var right = traverse(root.right,depth+1,diff);
        diff[0] = Math.max(diff[0],Math.abs(left-right));
        return 1+Math.max(left,right);
    }
}
