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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        traverse(root,res,0);
        return res;
    }
    public void traverse(TreeNode root,List<List<Integer>> res, int depth)
    {
        if(root==null)
            return;
        if(res.size()>depth)
            // 注意这里index是反过来的
            res.get(res.size()-depth-1).add(root.val);
        else
            res.add(0,new ArrayList<Integer>(Arrays.asList(root.val)));
        traverse(root.left,res,depth+1);
        traverse(root.right,res,depth+1);
    }

}
