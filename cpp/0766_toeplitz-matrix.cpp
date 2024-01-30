/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i=1; i < matrix.size(); i++){
            for (int j=1; j< matrix[0].size(); j++){
                if (matrix[i][j]!= matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

