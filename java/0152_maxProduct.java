class Solution {
    public int maxProduct(int[] nums) {
        int res=nums[0],f_max=nums[0],f_min=nums[0];
        for(var i=1;i<nums.length;i++)
        {
            int mx = f_max,mn=f_min;
            f_max = Math.max(mx*nums[i],Math.max(mn*nums[i],nums[i]));
            f_min = Math.min(mx*nums[i],Math.min(mn*nums[i],nums[i]));
            res = Math.max(res,f_max);
        }
        return res;
    }
}
