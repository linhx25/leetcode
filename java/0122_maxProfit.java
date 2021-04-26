class Solution {
    public int maxProfit(int[] prices) {
        int res=0;
        for(var i=1;i<prices.length;i++)
            res+=prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        return res;
    }
}
