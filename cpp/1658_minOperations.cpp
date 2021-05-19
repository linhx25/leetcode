// 这是一个两端连续的问题，记数组和为sum，则题目要求等价于寻找和为sum-x的最长连续子数组->sliding window
// 右指针正常右移
// 左指针主动右移：当出现满足window内和>=sum-x
// 每次符合条件则更新长度
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        x = -x;
        for(int& n:nums)
            x+=n;
        if(x<=0)
            return x==0?nums.size():-1;
        int res=0,sum=0;
        for(int left=0,right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while(left<nums.size() && sum>x)
                sum -=nums[left++];
            if(sum==x)
                res = max(res,right-left+1);
        }

        return res==0?-1:nums.size()-res;
    }
};
