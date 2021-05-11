// 1.二分搜索查到该值；
// 2.双指针向左、右扩大范围[因为二分法查到的值已经是最左/最右，所以只需要扩大一边]
// 3.二分法的细节：edge case
// 二分法左闭右开，如果解存在一定在闭区间里，因此最后拿到的是第一个解；
// 二分法左开右闭，则拿到的是最后一个解
// 左闭右开，如果解不存在，需要检测最后指针在右边界有无溢出，因为如果最后指针在左边界，一定是闭的
// 左开右闭，如果解不存在，则检测最后指针在左边界有无溢出。

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.size()<1)
            return res;
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid = left+right>>1;
            if(nums[mid]>=target)
                right = mid;
            else
                left = mid+1;
        }
        if(left<nums.size() && nums[left]==target)
            res[0] = left;
        if(res[0]==-1)
            return res;
        right = nums.size()-1;
        while(left<right)
        {
            int mid = (left+right)/2+(left+right)%2;
            if(nums[mid]>target)
                right = mid-1;
            else
                left = mid;
        }
        res[1] = left;
        return res;
    }
};
