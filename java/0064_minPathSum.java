class Solution {
    public int minPathSum(int[][] grid) {
        var dp = new int[2][grid[0].length];
        for(var col=0;col<grid[0].length;col++)
        {
            if(col==0)
                dp[0][0]=grid[0][0];
            else
                dp[0][col] = dp[0][col-1]+grid[0][col];
        }
        for(var row=1;row<grid.length;row++)
        {
            for(var col=0;col<grid[0].length;col++)
            {
                if(col==0)
                    dp[1][col] = dp[0][col] + grid[row][col];
                else
                    dp[1][col] = Math.min(dp[0][col],dp[1][col-1]) + grid[row][col];
            }
            for(var col=0;col<grid[0].length;col++)
                dp[0][col] = dp[1][col];
        }
        return dp[0][grid[0].length-1];
    }
}
