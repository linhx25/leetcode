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
        if(pos==nums.size())
        {
            res.push_back(comb);
            return;
        }
        comb.push_back(nums[pos]);
        backtrack(nums,res,pos+1,comb);//选取这个元素
        comb.pop_back();
        backtrack(nums,res,pos+1,comb);//不选取这个元素
    }
};
