// 0046是不含重复数字的全排列
// 回溯范围：全部元素排列
// 剪枝条件：已经访问，或者和上一元素重复（需要先排序）
// 终止：达到长度
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<int> visit(nums.size());
        sort(nums.begin(),nums.end());
        backtrack(res,nums,perm,visit);
        return res;
    }
    void backtrack(vector<vector<int>> &res,vector<int> &nums,vector<int> &perm,vector<int> &visit)
    {
        if(perm.size()==nums.size())
        {
            res.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visit[i]==1)
                continue;
            if(i>0 && nums[i]==nums[i-1] && visit[i-1]==0)
                continue;
            visit[i]=1;
            perm.push_back(nums[i]);
            backtrack(res,nums,perm,visit);
            visit[i]=0;
            perm.pop_back();
        }
    }
};
