class Solution {
    public int searchInsert(int[] nums, int target) {
        var p1=0;
        var p2=nums.length;
        while(p1<p2)
        {
            var mid = (p1+p2)/2;
            if(nums[mid]>=target)
                p2 = mid;
            else
                p1 = mid+1;
        }
        return p1;
    }
}
