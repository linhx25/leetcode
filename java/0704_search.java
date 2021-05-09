class Solution {
    public int search(int[] nums, int target) {
        int left=0,right=nums.length;
        while(left<right)
        {
            int mid = (right+left)/2;
            if(nums[mid]>=target)
                right = mid;
            else 
                left = mid+1;
        }
        return left<nums.length && nums[left]==target?left:-1;
    }
}
