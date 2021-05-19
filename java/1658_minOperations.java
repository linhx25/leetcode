class Solution {
    public int minOperations(int[] nums, int x) {
        x = -x;
        for(int n:nums)
            x+=n;
        if(x<=0)
            return x==0?nums.length:-1;
        int res=0,sum=0;
        for(int left=0,right=0;right<nums.length;right++)
        {
            sum += nums[right];
            while(left<nums.length && sum>x)
                sum -= nums[left++];
            if(sum==x)
                res = Math.max(res, right-left+1);
        }
        return res==0?-1:nums.length-res;
    }
}
