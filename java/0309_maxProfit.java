class Solution {
    public int maxProfit(int[] prices) {
        int dp0=-prices[0],dp1=0,dp2=0;
        for(var i=1;i<prices.length;i++)
        {
            int t0 = Math.max(dp0,dp2-prices[i]);
            int t1 = dp0 + prices[i];
            int t2 = Math.max(dp1,dp2);
            dp0 = t0;
            dp1 = t1;
            dp2 = t2;
        }
        return Math.max(dp1,dp2);
    }
}
