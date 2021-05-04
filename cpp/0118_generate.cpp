// dp: 类似0120
// 用一个数组储存上一行的数据，f[row,i]=f[row-1,i-1]+f[row-1,i]
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        for(auto row=1;row<numRows;row++)
        {
            res[row].push_back(1);
            for(auto col=1;col<row;col++)
                res[row].push_back(res[row-1][col]+res[row-1][col-1]);
            res[row].push_back(1);
        }
        return res;
    }
};
