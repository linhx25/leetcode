// dp: 用dp[i]代表以第i个位置为结尾的最长序列长度
// dp[i] = max(dp[argmax_{nums[idx]<nums[i]}]+1,dp[i]),if idx exist; else 1
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int res=1;
        for(auto i=1;i<nums.size();i++)
        {
            for(auto j=0;j<i;j++)
                if(nums[i]>nums[j])
                    dp[i] = max(dp[j]+1,dp[i]);
                
            res = max(dp[i],res);
        }
        return res;
    }
};
