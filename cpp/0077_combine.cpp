// 普通回溯
// 1.回溯范围：所有1到n的组合
// 2.剪枝条件：无
// 3.终止：达到要求长度k
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res,comb,n,1,k);
        return res;
    }
    void backtrack(vector<vector<int>> &res,vector<int>&comb,int n,int pos,int k)
    {
        if(comb.size()==k)
        {
            res.push_back(comb);
            return;
        }
        for(int i=pos;i<=n;i++)
        {
            comb.push_back(i);
            backtrack(res,comb,n,i+1,k);
            comb.pop_back();
        }
    }
};
