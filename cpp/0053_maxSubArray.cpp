// DP: 状态转移方程：记 P(t)为当前位置的最大子数组和，则
// P(t+1) = max(P(t),P(t)+element_t+1)
// 每次都用pre记录上一个位置的最大值，则可以根据状态转移方程推出此位置的最大值，
// 再将其与历史的最大值res比较，更新即可
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], pre = nums[0];
        for(auto i=1;i<nums.size();i++)
        {
            // 计算当前位置的最大值P(t)
            pre = max(nums[i]+pre,nums[i]);
            // 更新所有位置的最大值best
            res = max(pre,res);
        }
        return res;
    }
};
