// 对于任意一天，都有三种状态:
// 买入: dp[t][0] = max(dp[t-1][0],dp[t-1][2]-price[t])
// about to freeze: dp[t][1] = dp[t][0]+price[t]
// not freeze: dp[t][2] = max(dp[t-1][1],dp[t-1][2])
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp0= -prices[0],dp1=0,dp2=0;
        for(auto i=1;i<prices.size();i++)
        {
            int t0 = max(dp2-prices[i],dp0);
            int t1 = dp0 + prices[i];
            int t2 = max(dp1,dp2);
            dp0 = t0;
            dp1 = t1;
            dp2 = t2;
        }
        return max(dp1,dp2);
    }
};
