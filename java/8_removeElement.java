class Solution {
    public int removeElement(int[] nums, int val) {
        var p1=0;
        while(p1<nums.length && nums[p1]!=val)
            p1++;
        if(p1==nums.length)
            return p1;
        var p2=p1;
        while(p2<nums.length)
        {
            while(p2<nums.length && nums[p2]==val)
                p2++;
            if(p2==nums.length)
                break;
            nums[p1]=nums[p2];
            p1++;
            p2++;
        }
        return p1;
    }
}
