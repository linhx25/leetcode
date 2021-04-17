class Solution {
    public int firstMissingPositive(int[] nums) {
        for(var i=0;i<nums.length;i++)
            if(nums[i]<=0)
                nums[i] = nums.length+1;
        for(var i=0;i<nums.length;i++)
        {
            if(Math.abs(nums[i])<=nums.length && nums[Math.abs(nums[i])-1]>0)
                nums[Math.abs(nums[i])-1] *= -1;
        }
        for(var i=0;i<nums.length;i++)
            if(nums[i]>0)
                return i+1;
        return nums.length+1;
    }
}
