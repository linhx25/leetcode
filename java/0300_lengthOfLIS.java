class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0]=1;
        int res=1;
        for(var i=1;i<nums.length;i++)
        {
            dp[i]=1;
            for(var j=0;j<i;j++)
                if(nums[i]>nums[j])
                    dp[i] = Math.max(dp[i],dp[j]+1);
            res = Math.max(res,dp[i]);
        }
        return res;
    }
}
