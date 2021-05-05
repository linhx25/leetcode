// 与0309的做法基本一致
// 每天对应两个状态：买入，卖出
// dp[t][0] = max(dp[t-1][1]-prices[t]-fee,dp[t-1][0])
// dp[t][1] = max(dp[t-1][0]+prices[t],dp[t-1][1])
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp0=-prices[0]-fee,dp1=0;
        for(auto i=1;i<prices.size();i++)
        {
            int t0 = max(dp1-prices[i]-fee,dp0);
            int t1 = max(dp0+prices[i],dp1);
            dp0 = t0;
            dp1 = t1;
        }
        return dp1;
    }
};
