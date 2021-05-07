class Solution {
    public int coinChange(int[] coins, int amount) {
        var arr = new int[amount+1];
        return dfs(arr,coins,amount);
    }
    public int dfs(int[]arr,int[] coins,int amount)
    {
        if(amount<0)
            return -1;
        else if(amount==0)
            return 0;
        if(arr[amount]!=0)
            return arr[amount];
        
        int tmp = Integer.MAX_VALUE;
        for(int c:coins)
        {
            int ttmp = dfs(arr,coins,amount-c);
            if(ttmp>=0)
                tmp = Math.min(tmp,ttmp);
        }
        arr[amount] = tmp==Integer.MAX_VALUE?-1:tmp+1;
        return arr[amount];
    }
}
