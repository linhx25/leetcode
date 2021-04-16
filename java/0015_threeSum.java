import java.util.Arrays;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        var res = new ArrayList<List<Integer>>();
        if (nums.length<3)
            return res;
        
        Arrays.sort(nums);
        for (var a=0;a<nums.length-2;a++)
        {
            if (nums[a]>0)
                break;
            if (a>0 && nums[a]==nums[a-1])
                continue;
            var b = a+1;
            var c = nums.length-1;
            while (b<c)
            {  
                if((nums[a]+nums[b]+nums[c]) == 0)
                {
                    while(b<c && nums[b]==nums[b+1])
                        b++;
                    while(b<c && nums[c]==nums[c-1])
                        c--;
                    res.add(Arrays.asList(nums[a],nums[b],nums[c]));
                    b++;
                    c--;
                }
                else if((nums[a]+nums[b]+nums[c]) >0)
                    c--;
                else
                    b++;
            }
        }
        return res;
    }
}
