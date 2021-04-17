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
        auto res = vector<int>(2,-1);
        if(nums.size()==0)
            return res;

        int p1 = 0;
        int p2 = nums.size();
        int mid = 0;
        // 查找左边第一个值
        while(p1<p2)
        {
            mid = (p1+p2)/2;
            if(nums[mid]<target)
                p1 = mid+1;
            else if(target<=nums[mid])
                p2 = mid;
        }
        if(p1<nums.size() && nums[p1]==target)
            res[0] = p1;
        if(res[0]==-1)
            return res;

        // 改进：查找右边最后一个值
        p2 = nums.size()-1;
        while(p1<p2)
        {
            mid = (p1+p2)/2+(p1+p2)%2;
            if(target<nums[mid])
                p2 = mid-1;
            else if(nums[mid]<=target)
                p1 = mid;  
        }
        res[1]=p2;

        // 原始：右指针向右直到范围无法扩大
        // p2 = p1;
        // while(p2<nums.size()-1 && nums[p2]==nums[p2+1])
        //     p2++;
        // res[0]=p1;res[1]=p2;

        return res;
    }
};
