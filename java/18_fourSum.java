import java.util.Arrays;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        var res = new ArrayList<List<Integer>>();
        if (nums.length<4)
            return res;

        Arrays.sort(nums);
        for(var p1=0;p1<nums.length-3;p1++)
        {
            if(nums[0]>target && target>=0)
                break;
            if(nums[nums.length-1]<target && target<=0)
                break;
            if(p1>0 && nums[p1-1]==nums[p1])
                continue;
            for(var p2=p1+1;p2<nums.length-2;p2++)
            {
                if(p2>p1+1 && nums[p2-1]==nums[p2])
                    continue;
                var p3=p2+1;
                var p4=nums.length-1;
                while(p3<p4)
                {
                    if(nums[p1]+nums[p2]+nums[p3]+nums[p4] == target)
                    {
                        while(p3<p4 && nums[p3]==nums[p3+1])
                            p3++;
                        while(p3<p4 && nums[p4]==nums[p4-1])
                            p4--;
                        res.add(Arrays.asList(nums[p1],nums[p2],nums[p3],nums[p4]));
                        p3++;p4--;
                    }
                    else if (nums[p1]+nums[p2]+nums[p3]+nums[p4] > target)
                        p4--;
                    else
                        p3++;
                }
            }
        }
        return res;
    }
}
