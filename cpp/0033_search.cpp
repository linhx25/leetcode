// 太难了。。。重复做多几次。
// 首先判断二分查找点向前移动的case，最重要的是魔鬼的边界细节
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto res = -1;
        auto p1 = 0;
        auto p2 = nums.size();
        while(p1<p2)
        {
            auto mid = (p2+p1)/2;
            if(target>=nums[0] ^ nums[0]>=nums[mid] ^ nums[mid]>=target)
                p1 = mid + 1;
            else
                p2 = mid;
            if(nums[mid]==target)
            {
                res = mid;
                break;
            }   
        }
        return res;
    }
};
