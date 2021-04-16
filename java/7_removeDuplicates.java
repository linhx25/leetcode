class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length<2)
            return nums.length;
        int p1=0,p2=1;
        while(p2<nums.length)
        {
            while(p2<nums.length && nums[p2]==nums[p2-1])
                p2++;
            if(p2==nums.length)
                break;
            p1++;
            nums[p1]=nums[p2];
            p2++;
        }
        return 1+p1;
    }
}
