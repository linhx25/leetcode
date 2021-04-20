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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        traverse(root,res,0);
        return res;
    }
    public void traverse(TreeNode root,List<List<Integer>> res,int depth)
    {
        if(root==null)
            return;
        if(res.size()>depth)
        {
            if(depth%2==0)
                res.get(depth).add(root.val);
            else
                res.get(depth).add(0,root.val);
        }
        else
        {
            if(depth%2==0)
                res.add(new ArrayList<>(Arrays.asList(root.val)));
            else
                res.add(new LinkedList<>(Arrays.asList(root.val)));
        }
            
        traverse(root.left,res,depth+1);
        traverse(root.right,res,depth+1);
    }
}
