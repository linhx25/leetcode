// 回溯法：一种通过探索所有可能的候选解来找出所有的解的算法。如果候选解被确认不是一个解（或者至少不是最后一个解），回溯算法会通过在上一步进行一些变化抛弃该解，即回溯并且再次尝试.
// 1.要遍历所有的排列，因此是回溯
// 2.遍历范围：对于每个尝试的元素，都遍历其他所有的元素（包括自己）
// 3.回溯剪枝：对于已经visit过的元素，避免再次访问
// 4.终止：长度已经足够
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<int> visit(nums.size());
        backtrack(res, nums, perm, visit);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int> &nums, vector<int> &perm, vector<int> &visit)
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
            visit[i]=1;
            perm.push_back(nums[i]);
            backtrack(res,nums,perm,visit);
            perm.pop_back();
            visit[i]=0;
        }
    }
};
