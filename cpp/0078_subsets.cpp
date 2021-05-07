// 1.回溯范围：所有子集的组合
// 2.剪枝条件：无
// 3.终止：遍历位置达到数组的长度
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(nums,res,0,comb);
        return res;
    }
    void backtrack(vector<int>&nums, vector<vector<int>> &res, int pos, vector<int> &comb)
    {
        res.push_back(comb);
        for(int i=pos;i<nums.size();i++)
        {
            comb.push_back(nums[i]);
            backtrack(nums,res,i+1,comb);
            comb.pop_back();
        }
    }
};
