// 太难了。。。状态转移方程
// 除了未进行任何操作，任意时刻的利润还存在以下4种状态：
// 1.首次买入：buy1_t = max(buy1_t-1,-prices[t]) // 不做操作，或者执行首次买入
// 2.首次卖出：sell1_t = max(sell1_t-1,buy1_t+prices[t]) // 不做操作，或者执行首次卖出
// 3.第二次买入: buy2_t = max(buy2_t-1,sell1_t-prices[t]) // 不做操作，或者执行第二次买入
// 4.第二次卖出: sell2_t = max(sell2_t-1,buy2_t+prices[t]) // 不做操作，或者执行首次买入
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1=-prices[0],sell1=0,buy2=-prices[0],sell2=0;
        for(auto i=1;i<prices.size();i++)
        {
            buy1 = max(buy1,-prices[i]);
            sell1 = max(sell1,buy1+prices[i]);
            buy2 = max(buy2,sell1-prices[i]);
            sell2 = max(sell2,buy2+prices[i]);
        }
        return sell2;
    }
};
