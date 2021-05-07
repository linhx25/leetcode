// 与78类似，这里排序后
// 剪枝条件：判断是否上一个数与该数相同，且上一个数没有被记录过
// 太混乱了。。。得把回溯的题目再整理一下
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(nums.begin(),nums.end());
        backtrack(res,comb,nums,0,false);
        return res;
    }
    void backtrack(vector<vector<int>> &res,vector<int> &comb,vector<int>&nums,int pos,bool visit)
    {
        if(pos==nums.size())
        {
            res.push_back(comb);
            return;
        }
        // 不选取第pos个数，直接到下一个pos
        backtrack(res,comb,nums,pos+1,false);
        // 选取第pos个数，此时先考虑1.是否之前被选，且2.是否之前被选的是重复的数，若是，则跳过
        if(!visit && pos>0 && nums[pos]==nums[pos-1])
            return;
        // 否则，选择第pos个数
        comb.push_back(nums[pos]);
        backtrack(res,comb,nums,pos+1,true);
        comb.pop_back();
    }
};
