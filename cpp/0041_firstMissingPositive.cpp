// 1.给定长度N的数组，最小的正整数应该在【1，N+1】之间
// 1.5先把负值修改为N+1
// 2.遍历数组，如果该位置对应的值在【1，N+1】之间，则把该值所在位置的元素标记为负（不影响绝对值）
// 3.遍历完成后大家都完成了标记，没有标记为负的元素对应的位置就是所求最小的值

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 修改不在【1，N】的数，修改后所有的数都>=1 
        for(auto p=nums.begin();p<nums.end();p++)
            if(*p<=0)
                *p = nums.size()+1;
        // 对于所有值在【1，N】的元素，说明该值代表的位置应该标记（为负）
        for(auto i=0;i<nums.size();i++)
        {
            if(abs(nums[i])<=nums.size() && nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] *= -1;
        }
        // 找到第一个没有被标记的元素的位置，+1即是缺失的最小正数
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        return nums.size()+1;
    }
};
