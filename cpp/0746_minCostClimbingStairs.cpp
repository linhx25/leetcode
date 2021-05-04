// 类似0070，dp[i]表示第i个台阶之前所积攒的体力花费(不包括此台阶)
// dp[i] = min(dp[i-1]+A[i-1],dp[i-2]+A[i-2])
// edge： 初始可以在0，1台阶开始，因此dp[0]=dp[1]=0
// 结束时要到第n+1个位置dp[n]，因为dp表示的是第i个台阶之前所积攒的体力花费
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ppre = 0,pre=0;
        
        for(auto i=2;i<=cost.size();i++)
        {
            int cur = min(pre+cost[i-1],ppre+cost[i-2]); 
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};
