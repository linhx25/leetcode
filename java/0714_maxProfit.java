class Solution {
    public int maxProfit(int[] prices, int fee) {
        int dp0=-prices[0]-fee,dp1=0;
        for(var i=1;i<prices.length;i++)
        {
            int t0 = Math.max(dp1-prices[i]-fee,dp0);
            int t1 = Math.max(dp0+prices[i],dp1);
            dp0 = t0;
            dp1 = t1;
        }
        return dp1;
    } 
}
