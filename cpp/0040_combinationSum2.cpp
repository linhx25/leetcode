// 与0039的不同在于每个元素只能选择一次
// 回溯范围：遍历所有的组合
// 剪枝条件：当目前的sum已经大于target（需要先排序);当目前的元素和上一元素重复
// 终止：sum==target
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> comb;
        sort(candidates.begin(),candidates.end());
        backtrack(res,candidates,target,comb,0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int>& candidates, int target, vector<int>&comb, int idx)
    {
        if(target==0)
        {
            res.push_back(comb);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(target-candidates[i]<0)
                return;
            if(i>idx && candidates[i]==candidates[i-1])
                continue;

            comb.push_back(candidates[i]);
            backtrack(res,candidates,target-candidates[i],comb,i+1);
            comb.pop_back();
        }
    }
};
