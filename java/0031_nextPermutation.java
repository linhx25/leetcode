class Solution {
    public void nextPermutation(int[] nums) {
        var p2 = nums.length - 1;
        var p1 = p2 - 1;
        while(p1>=0 && nums[p1]>=nums[p1+1])
            p1--;
        if(p1>=0)
        {
            while(p2>p1 && nums[p1]>=nums[p2])
                p2--;
            swap(nums,p1,p2);
        }
        p1++;
        p2 = nums.length-1;
        while(p1<p2)
        {
            swap(nums,p1,p2);
            p1++;p2--;
        }
    }
    public void swap(int[] nums,int a,int b)
    {
        var tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
}
