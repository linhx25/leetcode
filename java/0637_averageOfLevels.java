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
    public List<Double> averageOfLevels(TreeNode root) {
        List<List<Double>> record = new ArrayList<List<Double>>();
        traverse(root,record,0);
        List<Double> res = new ArrayList<Double>();
        for(var i=0;i<record.size();i++)
            res.add(record.get(i).get(0)/record.get(i).get(1));
        return res;
    }
    public void traverse(TreeNode root,List<List<Double>> record,int depth)
    {
        if(root==null)
            return;
        if(record.size()>depth)
        {
            record.get(depth).set(0,record.get(depth).get(0)+root.val);
            record.get(depth).set(1,record.get(depth).get(1)+1);
        }
        else
        {
            List<Double> t = new ArrayList<Double>();
            t.add((double)root.val);
            t.add(1.0);
            record.add(t);
        }
        traverse(root.left,record,depth+1);
        traverse(root.right,record,depth+1);
    }
}
