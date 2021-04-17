class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1,-1};
        if(nums.length==0)
            return res;
        var p1 = 0;
        var p2 = nums.length;
        while(p1<p2)
        {
            var mid = (p1+p2)/2;
            if(nums[mid]>=target)
                p2 = mid;
            else
                p1 = mid+1;
        }
        if(p1<nums.length && nums[p1]==target)
            res[0] = p1;
        if(res[0]==-1)
            return res;

        p2 = nums.length-1;
        while(p1<p2)
        {
            var mid = (p1+p2)/2 + (p1+p2)%2;
            if(nums[mid]<=target)
                p1 = mid;
            else
                p2 = mid-1;
        }
        res[1]=p2;
        return res;
    }
}
