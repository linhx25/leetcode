class Solution {
    public int singleNonDuplicate(int[] nums) {
        if(nums.length<2)
            return nums[0];
        int left=0,right=nums.length-1;
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
}
