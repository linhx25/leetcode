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
    public int minDepth(TreeNode root) {
        if(root==null)
            return 0;
        int[] res = {10000000};
        traverse(root,0,res);
        return res[0];
    }
    public void traverse(TreeNode root,int depth,int[] res)
    {
        if(root==null)
            return;
        if(root.right==null && root.left==null)
            res[0] = Math.min(res[0],depth+1);
        traverse(root.left,depth+1,res);
        traverse(root.right,depth+1,res);
    }
}
