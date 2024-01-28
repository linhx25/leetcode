/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size(); 
        if (row==0) return -1;
        int col = grid[0].size();
        if (col==0) return -1;
        if (grid[0][0]==1 || grid[row-1][col-1]==1) return -1;
        
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<vector<int>> directions = {{1,1},{1,0},{0,1},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1}};
        grid[0][0] = 1;
        while(!q.empty()){
            auto curr = q.front();
            int x = curr.first, y = curr.second;
            if(x == row-1 && y == col-1) return grid[x][y];
            for (auto d:directions){
                auto nx = x + d[0], ny = y + d[1];
                if (0 <= nx && nx < row && 0 <= ny && ny < col && grid[nx][ny]==0){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
            q.pop();
        }
        return -1;
    }
};
// @lc code=end

