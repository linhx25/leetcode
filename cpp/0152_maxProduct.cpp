// dp: 这里的最优子结构要考虑最大值、最小值的情况，因为乘积可能是负的
// f_max(n) = max(f_max(n-1)*A_n, f_min(n-1)*A_n, A_n)
// f_min(n) = min(f_max(n-1)*A_n, f_min(n-1)*A_n, A_n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0],f_max = nums[0],f_min = nums[0];
        for(auto i=1;i<nums.size();i++)
        {
            int mx =f_max,mn = f_min; // storing variables
            f_max = max(max(mx*nums[i],mn*nums[i]),nums[i]);
            f_min = min(min(mx*nums[i],mn*nums[i]),nums[i]);
            res = max(res,f_max);
        }
        return res;
    }
};
