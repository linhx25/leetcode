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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> r1 = new ArrayList<Integer>();
        List<Integer> r2 = new ArrayList<Integer>();
        traverse(root1,r1);
        traverse(root2,r2);
        if(r1.size()!=r2.size())
            return false;
        for(var i=0;i<r1.size();i++)
            if(r1.get(i)!=r2.get(i))
                return false;
        return  true;
    }
    public void traverse(TreeNode root,List<Integer> record)
    {
        if(root==null)
            return;
        if(root.left==null && root.right==null)
            record.add(root.val);
        traverse(root.left,record);
        traverse(root.right,record);
    }
}
