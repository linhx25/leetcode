class Solution {
    public int[] twoSum(int[] nums, int target) {
        var map = new HashMap<Integer,Integer>(); // number-location pairs
        var item_i = nums[0];
        var res = new int[2];
        map.put(item_i,0);

        for (var i=1;i<nums.length;i++)
        {
            if (item_i==target-nums[i])
            {
                res[0]=i;
                res[1]=map.get(item_i);
                break;
            }
            else
            {
                if (map.containsKey(target-nums[i]))
                {
                    res[0] = map.get(target-nums[i]);
                    res[1] = i;
                    break;
                }
                map.put(nums[i],i);
            }
        } 
        return res;
    }
}

