// dp:难点在于写出状态转移方程,f[i,j]代表str0[begin=0,length=i] and str1[0,j]的最长公共子序列长度
// edge: f[0,j]=f[i,0]=0
// f[i,j] = 
// f[i-1,j-1]+1, if str0[i]==str[j];
// max(f[i-1,j],f[i,j-1]), else where.
// 空间优化：只需要上一行的数组
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size()+1);
        for(auto row=1;row<=text1.size();row++)
        {
            dp[0]=0;
            vector<int> dp_pre(dp);// 储存dp[i-1,:]
            for(auto col=1;col<=text2.size();col++)
            {
                if(text2[col-1]!=text1[row-1])
                    dp[col] = max(dp_pre[col],dp[col-1]);
                else
                    dp[col] = dp_pre[col-1]+1;
            }
        }
        return dp[text2.size()];
    }
};
