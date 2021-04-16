import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = 100000;
        for (var i=0;i<nums.length-2;i++)
        {
            int j=i+1;
            int k=nums.length-1;
            while (j<k)
            {
                if(Math.abs(nums[i]+nums[j]+nums[k]-target)<Math.abs(res-target))
                    res = nums[i]+nums[j]+nums[k];
                if(nums[i]+nums[j]+nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
}
