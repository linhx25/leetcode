// 1.greedy: 遍历数组，寻求max sum(p_i - p_i-1)
// 2.只需每次选取差>1的区间即可
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(auto i=1;i<prices.size();i++)
            res+=prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        return res;
    }
};
