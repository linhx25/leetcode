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
// 小心java的数组都是对象，应该copy数组
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> arr = new ArrayList<Integer>();
        traverse(root,targetSum,0,1,res,arr);
        return res;
    }
    public void traverse(TreeNode root,int targetSum,int sum, int depth,List<List<Integer>> res, List<Integer> arr)
    {
        if(root==null)
            return;
        while(arr.size()>=depth)
            arr.remove(arr.size()-1);
        arr.add(root.val);
        if(root.right==null && root.left==null && root.val+sum==targetSum)
            res.add(new ArrayList<Integer>(arr));
        traverse(root.left,targetSum,sum+root.val,depth+1,res,arr);
        traverse(root.right,targetSum,sum+root.val,depth+1,res,arr);
    }
}
