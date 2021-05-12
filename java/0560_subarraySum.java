class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> m = new HashMap<>();
        int pre=0,res=0;
        m.put(0,1);
        for(var i=0;i<nums.length;i++)
        {
            pre+=nums[i];
            if(m.containsKey(pre-k))
                res += m.get(pre-k);
            m.put(pre,m.getOrDefault(pre,0)+1);
        }
        return res;
    }
}
