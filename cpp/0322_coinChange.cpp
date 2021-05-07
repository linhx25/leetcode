// gan, 又好难。。。。
// 用回溯会超时，改用dp: 用f(amount)表示amount金额对应的最小硬币数
// f(amount_t) = min(f(amount_{t-1})) + 1
// f(0)=0
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> arr(amount+1);
        return dfs(arr,coins,amount);
    }
    int dfs(vector<int>&arr,vector<int>& coins,int amount)
    {
        // 组合已经完成目标
        if(amount==0)
            return 0;
        // 没有找到相应的组合
        if(amount<0)
            return -1;
        // 如果已经记录过amount的最少硬币数,不再重复遍历
        if(arr[amount]!=0)
            return arr[amount];

        int tmp = INT_MAX;
        for(auto c:coins)
        {
            int ttmp = dfs(arr,coins,amount-c);
            if(ttmp>=0)
                tmp = min(tmp,ttmp);
        }
        arr[amount] = tmp==INT_MAX?-1:tmp+1;
        return arr[amount];
    }
};
