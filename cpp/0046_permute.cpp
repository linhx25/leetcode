// 回溯法：一种通过探索所有可能的候选解来找出所有的解的算法。如果候选解被确认不是一个解（或者至少不是最后一个解），回溯算法会通过在上一步进行一些变化抛弃该解，即回溯并且再次尝试.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,0,res);
        return res;
    }
    void backtrack(vector<int> &nums, int pos, vector<vector<int>>& res)
    {
        if(pos==nums.size())
        {
            res.push_back(nums);
            return;
        }    
        for(auto i=pos;i<nums.size();i++)
        {
            swap(nums[pos],nums[i]);
            backtrack(nums,pos+1,res);
            swap(nums[pos],nums[i]);
        }
    }
};
