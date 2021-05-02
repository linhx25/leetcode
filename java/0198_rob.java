class Solution {
    public int rob(int[] nums) {
        if(nums.length<2)
            return nums[0];
        int p1 = nums[0],p2=Math.max(nums[0],nums[1]);
        for(var i=2;i<nums.length;i++)        
        {
            int tmp = p2;
            p2 = Math.max(p1+nums[i],p2);
            p1 = tmp;
        }
        return p2;
    }
}
