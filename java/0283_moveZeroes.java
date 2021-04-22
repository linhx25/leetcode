class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length<2)
            return;
        int p1=0;
        while(p1<nums.length && nums[p1]!=0)
            p1++;
        int p2 = p1;
        while(p2<nums.length)
        {
            while(p2<nums.length && nums[p2]==0)
                p2++;
            if(p2==nums.length)
                break;
            var t = nums[p2];
            nums[p2] = nums[p1];
            nums[p1] = t;
            p1++;p2++;
        }
    }
}
