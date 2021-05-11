// Repeat:2
// 太难了。。。重复做多几次。
// 首先判断二分查找点向前移动的case，最重要的是魔鬼的边界细节
// forward move mid:
// nums[0]<=target<=nums[mid]
// nums[mid]<nums[0]<=target
// target<=nums[mid]<nums[0]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid = (left+right)>>1;
            if((nums[0]<=target&&target<=nums[mid]) || (nums[mid]<nums[0]&&nums[0]<=target) || (target<=nums[mid]&&nums[mid]<nums[0]))
                right = mid;
            else
                left = mid+1;
        }
        return left<nums.size()?(nums[left]==target?left:-1):-1;
    }
};
