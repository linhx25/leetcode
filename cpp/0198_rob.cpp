// dp: f(n) = max(f(n-1),A_n + f(n-2))
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        int p1=nums[0],p2=max(nums[0],nums[1]);
        for(auto i=2;i<nums.size();i++)
        {
            int tmp = p2;
            p2 = max(p1+nums[i],p2);
            p1 = tmp;
        }
        return p2;
    }
};
