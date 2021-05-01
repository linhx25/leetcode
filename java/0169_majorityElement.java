class Solution {
    public int majorityElement(int[] nums) {
        int count=1;
        int res=nums[0];
        for(var i=1;i<nums.length;i++)
        {
            if(count==0)
                res = nums[i];
            count += res==nums[i]? 1 : -1;
        }
        return res;
    }
}
