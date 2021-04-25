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
    public int pathSum(TreeNode root, int targetSum) {
        int[] res = {0};
        List<Integer> arr = new ArrayList<Integer>();
        traverse(root,targetSum,arr,1,res);
        return res[0];
    }
    public void traverse(TreeNode root,int targetSum,List<Integer> arr,int depth, int[] res)
    {
        if(root==null)
            return;
        while(arr.size()>=depth)
            arr.remove(arr.size()-1);
        arr.add(root.val);
        int sum=0;
        for(var i=arr.size()-1;i>=0;i--)
        {
            sum += arr.get(i);
            if(sum==targetSum)
                res[0]++;
        }
        traverse(root.left,targetSum,arr,depth+1,res);
        traverse(root.right,targetSum,arr,depth+1,res);
    }
}
