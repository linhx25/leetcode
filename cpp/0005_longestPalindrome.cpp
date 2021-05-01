// dp: 设dp[i,j]代表i到j的子串是否是回文
// 则状态转移方程为d[i,j] = d[i+1,j-1] && d[i]==d[j]
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1)
            return s;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        int begin=0;
        int maxLen=1;
        // 从长度为1开始遍历（状态转移方程的递推
        for(auto L=1;L<=s.size();L++)
        {
            // 遍历每个起点
            for(auto i=0;i<s.size();i++)
            {
                int j = i+L-1;
                if(j>=s.size())
                    break;
                //长度为1
                if(j==i)
                {
                    dp[i][j] = true;
                    if(L>maxLen)
                    {
                        begin = i;
                        maxLen = L;
                    }
                }
                else if(j-i==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = true;
                        if(L>maxLen)
                        {
                            begin = i;
                            maxLen = L;
                        }
                    }
                }
                else
                {
                    if(dp[i+1][j-1] && s[i]==s[j])
                    {
                        dp[i][j]=true;
                        if(L>maxLen)
                        {
                            begin = i;
                            maxLen = L;
                        }
                    }
                }   
            }
        }
        return s.substr(begin,maxLen);
    }
};