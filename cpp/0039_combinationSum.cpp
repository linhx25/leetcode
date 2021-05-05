// backtrack(candidates,target,idx)代表当前已经搜索到candidates的第idx个位置
// 1.不搜索第idx，搜索下一个
// 2.搜索idx
// 对candidates排序，如果已经大于target，直接跳出
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res,comb,candidates,target,0);
        return res;
    }
    void backtrack(vector<vector<int>>&res, vector<int> &comb, vector<int> &candidates,int target,int idx)
    {
        if(idx>=candidates.size())
            return;
        if(target==0)
        {
            res.push_back(comb);
            return;
        }
        if(target-candidates[idx]>=0)
        {
            comb.push_back(candidates[idx]);
            backtrack(res,comb,candidates,target-candidates[idx],idx);
            comb.pop_back();
        }
        else
            return;
        backtrack(res,comb,candidates,target,idx+1);
    }
};
