class Solution {
    public int[] productExceptSelf(int[] nums) {
        var res = new int[nums.length];
        res[0]=1;
        int right=1;
        for(var i=1;i<nums.length;i++)
            res[i] = res[i-1]*nums[i-1];
        for(var i=nums.length-2;i>0;i--)
        {
            right *= nums[i+1];
            res[i] *= right;
        }
        res[0] = right * nums[1];
        return res;
    }
}
