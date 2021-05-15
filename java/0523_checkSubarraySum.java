class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        Map<Integer,Integer> m = new HashMap<>();
        m.put(0,-1);
        for(int i=0;i<nums.length;i++)
        {
            sum+=nums[i];
            sum%=k;
            if(m.containsKey(sum))
            {
                if(i-m.get(sum)>=2)
                    return true;
            }
            else
                m.put(sum,i);
        }
        return false;
    }
}
