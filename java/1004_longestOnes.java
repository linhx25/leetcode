class Solution {
    public int longestOnes(int[] nums, int k) {
        if(nums.length<=k)
            return nums.length;
        int p1=0,p2=0,res=0,count=0;
        while(p2<nums.length)
        {
            if(nums[p2]==0)
                count++;
            while(count>k)
            {
                if(nums[p1]==0)
                    count--;
                p1++;
            }
            res = Math.max(res,++p2-p1);
        }
        return res;
    }
}