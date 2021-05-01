class Solution {
    public int maxProfit(int[] prices) {
        int hist=100000;
        int res=0;
        for(var i=0;i<prices.length;i++)
        {
            if(prices[i]<hist)
                hist = prices[i];
            res = Math.max(res,prices[i]-hist);
        }
        return res;
    }
}
