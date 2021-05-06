// 1.回溯范围：所有1-9的组合
// 2.剪枝条件：当数量超过k或者相加之和大于n
// 3.终止：当数量等于k且相加之和等于n
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res,k,n,comb,1);
        return res;
    }
    void backtrack(vector<vector<int>> &res, int k, int target, vector<int> &comb, int pos)
    {
        if(comb.size()==k && target==0)
        {
            res.push_back(comb);
            return;
        }
        for(int i=pos;i<10;i++)//1-9
        {
            if(target-i<0 || comb.size()>k)
                return;
            comb.push_back(i);
            backtrack(res,k,target-i,comb,i+1);
            comb.pop_back();
        }
    }
};
