// 先存储在不用技巧时customers满意度的和
// 接着用sliding window遍历grumpy，满意度的增加等于窗口对应位置的全部满意度之和
// 滑动时更新最大新增满意度
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
        int maxIncrease=0,sat=0;
        for(int i=0;i<customers.size();i++)
        {
            maxIncrease -= customers[i];//初始化，以便当x>length时使用
            sat += customers[i]*(int)(grumpy[i]==0);
        }
        if(x>=customers.size())
            return -maxIncrease;
        int increase =0;
        for(int i=0;i<x;i++)
            increase += customers[i]*grumpy[i];
        maxIncrease = increase;
        for(int j=x;j<customers.size();j++)
        {
            increase = increase-customers[j-x]*grumpy[j-x]+customers[j]*grumpy[j];
            maxIncrease = max(maxIncrease,increase);
        }
        return maxIncrease+sat;
    }
};
