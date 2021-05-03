// dp, 类似0064是长方形
// f[i,j] = min (f[i-1,j-1],f[i-1,j]) + A[i,j]; j<length_i-1 && j!=0
// f[i,0] = f[i-1,0] + A[i,j];
// f[i,length_i] = f[i-1,length_i-1] + A[i,j]
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<2)
            return triangle[0][0];
        vector<vector<int>> dp(2);
        dp[0] = vector<int>(1,triangle[0][0]);
        dp[1] = vector<int>(2);
        for(auto row=1;row<triangle.size();row++)
        {
            for(auto col=0;col<triangle[row].size();col++)
            {
                if(col==0)
                    dp[1][col] = dp[0][col] + triangle[row][col];
                else if(col==triangle[row].size()-1)
                    dp[1][col] = dp[0][col-1] + triangle[row][col];
                else 
                    dp[1][col] = min(dp[0][col],dp[0][col-1]) + triangle[row][col];
            }
            dp.erase(dp.begin());
            dp.push_back(vector<int>(triangle[row].size()+1));
        }
        int res=dp[0][0];
        for(auto i=1;i<dp[0].size();i++)
            if(dp[0][i]<res)
                res = dp[0][i];
        return res;
    }
};
