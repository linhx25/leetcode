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
import java.util.Arrays;
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        traverse(0,root,res);
        return res;
    }
    public void traverse(int depth,TreeNode root,List<List<Integer>> res)
    {
        if(root==null)
            return;
        
        if(res.size()>depth)
            res.get(depth).add(root.val);
        else
        {
            var t = new ArrayList<Integer>();
            t.add(root.val);
            res.add(t);
        }
        traverse(depth+1,root.left,res);
        traverse(depth+1,root.right,res);
    }
}
