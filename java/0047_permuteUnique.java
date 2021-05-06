class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> perm = new ArrayList<Integer>();
        var visit = new int[nums.length];
        Arrays.sort(nums);
        backtrack(res,nums,perm,visit);
        return res;
    }
    public void backtrack(List<List<Integer>> res,int[] nums,List<Integer> perm, int[] visit)
    {
        if(perm.size()==nums.length)
        {
            res.add(new ArrayList<Integer>(perm));
            return;
        }
        for(var i=0;i<nums.length;i++)
        {
            if(visit[i]==1)
                continue;
            if(i>0 && nums[i]==nums[i-1] && visit[i-1]==0)
                continue;
            visit[i]=1;
            perm.add(nums[i]);
            backtrack(res,nums,perm,visit);
            visit[i]=0;
            perm.remove(perm.size()-1);
        }
        
    }
}
