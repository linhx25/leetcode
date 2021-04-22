class Solution {
    public int maxSubArray(int[] nums) {
        int pre = nums[0];
        int res = nums[0];
        for(var i=1;i<nums.length;i++)
        {
            pre = Math.max(nums[i],nums[i]+pre);
            res = Math.max(pre,res);
        }
        return res;
    }
}