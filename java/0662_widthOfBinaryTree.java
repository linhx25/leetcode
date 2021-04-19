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
    public int widthOfBinaryTree(TreeNode root) {
        var record = new ArrayList<Integer>();
        int[] res = {1};
        traverse(root,record,res,0,0);
        return res[0];
    }
    public void traverse(TreeNode root, List<Integer> record, int[] res, int depth, int position)
    {
        if(root==null)
            return;
        if(record.size()<depth+1)
            record.add(position);
        res[0] = Math.max(res[0],position-record.get(depth)+1);
        traverse(root.left,record,res,depth+1,position*2);
        traverse(root.right,record,res,depth+1,position*2+1);
    }
}
