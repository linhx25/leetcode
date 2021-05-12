// Repeat:2
// 就是二分查找，还不需要判断有无查到
// 注意左闭右开时，如果查得到，会停在第一个出现的元素（若有重复），可以由闭区间不断向取左子覆盖想象到；
// 如果查不到，会停在第一个比该元素大的位置上
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int p1=0,p2=nums.size();
        while(p1<p2)
        {
            int mid = (p1+p2)/2;
            if(nums[mid]>=target)
                p2 = mid;
            else
                p1 = mid+1;
        }
        return p1;
    }
};
