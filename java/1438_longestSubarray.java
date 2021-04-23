// TreeMap
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        if(nums.length==0)
            return 0;
        int p1=0,p2=0,res=0;
        TreeMap<Integer,Integer> t = new TreeMap<>();
        while(p2<nums.length)
        {
            if(t.get(nums[p2])!=null)
                t.put(nums[p2],1+t.get(nums[p2]));
            else
                t.put(nums[p2],1);
            while(p1<=p2 && t.lastKey()-t.firstKey()>limit)
            {
                t.put(nums[p1],t.get(nums[p1])-1);
                if(t.get(nums[p1])==0)
                    t.remove(nums[p1]);
                p1++;
            }
            res = Math.max(res,++p2-p1);
        }
        return res;
    }
}
