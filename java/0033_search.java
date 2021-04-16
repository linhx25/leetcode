class Solution {
    public int search(int[] nums, int target) {
        var res = -1;
        var p1 = 0;
        var p2 = nums.length;
        while(p1<p2)
        {
            var mid = (p1+p2)/2;
            if((target>=nums[0] && nums[0]>=nums[mid] && nums[mid]<target) ||
            (target>=nums[0] && nums[0]<nums[mid] && nums[mid]>=target) ||
            (target<nums[0] && nums[0]>=nums[mid] && nums[mid]>=target))
                p2 = mid;
            else
                p1 = mid + 1;
            if(target==nums[mid])
            {
                res = mid;
                break;
            }
        }
        return res;
    }
}
