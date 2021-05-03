// dp: 每个位置的最优路径只能是左边或上边位置得来
// f[i,j] = min(f[i-1,j],f[i,j-1])+A[i,j],i!=0,j!=0
// f[i,0] = f[i-1,0]+A[i,j]
// f[0,j] = f[0,j-1]+A[i,j]
// 空间优化：每次只需要上一行的数组即可
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(2,vector<int>(grid[0].size()));
        for(auto col=0;col<grid[0].size();col++)
        {
            if(col==0)
                dp[0][0] = grid[0][0];
            else
                dp[0][col] = grid[0][col]+dp[0][col-1];
        }
            
        for(auto row=1;row<grid.size();row++)
        {
            for(auto col=0;col<grid[0].size();col++)
            {
                if(col==0)
                    dp[1][col] = dp[0][col] + grid[row][col];
                else
                    dp[1][col] = min(dp[0][col],dp[1][col-1]) + grid[row][col];
            }
            dp.erase(dp.begin());
            dp.push_back(vector<int>(grid[0].size()));
        }
        return dp[0][grid[0].size()-1];
    }
};
