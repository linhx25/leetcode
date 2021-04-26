class Solution {
    public boolean canJump(int[] nums) {
        int dist=0;
        for(int i=0;i<nums.length;i++)
        {
            if(dist>=nums.length-1)
                return true;
            if(i<=dist)
                dist = Math.max(dist,i+nums[i]);
            else
                return false;
        }
        return false;
    }
}
