// Binary Search
// 如果中位数两边的元素数量是偶数，答案要么是中位数，要么在与中位数连续的一边；
// 如果中位数两边的元素数量是奇数，答案只能在不与中位数连续的一边。
// 注意细节：处理只有1个元素的情况，其他情况不可能溢出。
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid = (left+right)>>1;
            if(mid%2==0)
            {
                if(nums[mid+1]==nums[mid])
                    left = mid+2;
                else if(nums[mid-1]==nums[mid])
                    right = mid-2;
                else
                    return nums[mid];
            }
            else
            {
                if(nums[mid+1]==nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return nums[left];
    }
};
