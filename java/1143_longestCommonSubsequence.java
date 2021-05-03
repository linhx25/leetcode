class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[] dp = new int[text2.length()+1];
        for(var row=1;row<=text1.length();row++)
        {
            dp[0]=0;
            var dp_pre = dp.clone();
            for(var col=1;col<=text2.length();col++)
            {
                if(text2.charAt(col-1)!=text1.charAt(row-1))
                    dp[col] = Math.max(dp[col-1],dp_pre[col]);
                else
                    dp[col] = dp_pre[col-1]+1;
            }
        }
        return dp[text2.length()];
    }
}
