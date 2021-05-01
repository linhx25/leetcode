// 122是多次买卖，121是一次买卖
// 用一个hist记录当前的历史最低价格点
// 遍历计算最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hist=100000;
        int res=0;
        for(auto p:prices)
        {
            if(p<hist)
                hist=p;
            res = max(res,p-hist);
        }
        return res;
    }
};
