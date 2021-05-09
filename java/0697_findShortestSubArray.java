class Solution {
    public int findShortestSubArray(int[] nums) {
        var m = new HashMap<Integer, int[]>();
        for(var i=0;i<nums.length;i++)
        {
            if(m.containsKey(nums[i]))
            {
                m.get(nums[i])[0]++;
                m.get(nums[i])[2]=i;
            }
            else
            {
                m.put(nums[i],new int[3]);
                m.get(nums[i])[0]=1;
                m.get(nums[i])[1]=i;
                m.get(nums[i])[2]=i;
            }
        }
        int res=nums.length,count=1;
        for(var k:m.keySet())
        {
            if(count<m.get(k)[0])
            {
                res = m.get(k)[2]-m.get(k)[1]+1;
                count = m.get(k)[0];
            }
            else if(count==m.get(k)[0])
                res = Math.min(res,m.get(k)[2]-m.get(k)[1]+1);
        }
        return res;
    }
}
