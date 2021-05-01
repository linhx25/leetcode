class Solution {
    public String longestPalindrome(String s) {
        if(s.length()==1)
            return s;
        int maxLen=1;
        int begin=0;
        var dp = new boolean[s.length()][s.length()];
        for(var L=1;L<=s.length();L++)
        {
            for(var i=0;i<s.length();i++)
            {
                var j = i+L-1;
                if(j>=s.length())
                    break;
                if(i==j)
                {
                    dp[i][j]=true;
                    if(L>maxLen)
                    {
                        begin=i;
                        maxLen = L;
                    }
                }
                else if(i==j-1)
                {
                    if(s.charAt(i)==s.charAt(j))
                    {
                        dp[i][j]=true;
                        if(L>maxLen)
                        {
                            begin=i;
                            maxLen=L;
                        }
                    }
                }
                else
                {
                    if(dp[i+1][j-1] && s.charAt(i)==s.charAt(j))
                    {
                        dp[i][j]=true;
                        if(L>maxLen)
                        {
                            begin=i;
                            maxLen=L;
                        }
                    }
                }
            }
        } 
        return s.substring(begin,begin+maxLen);
    }
}