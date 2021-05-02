class Solution {
    public int res = 0;
    public int findTargetSumWays(int[] nums, int target) {
        find(nums,target,0,0);
        return res;
    }
    public void find(int[] nums,int target,int pos,int sum)
    {
        if(pos==nums.length)
        {
            if(sum==target)
                res++;
            return;
        }
        find(nums,target,pos+1,sum+nums[pos]);
        find(nums,target,pos+1,sum-nums[pos]);
    }
}
