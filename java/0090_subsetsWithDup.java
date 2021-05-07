class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        Arrays.sort(nums);
        backtrack(res,comb,nums,0,false);
        return res;
    }
    public void backtrack(List<List<Integer>> res, List<Integer> comb, int[] nums,int pos,boolean visit)
    {
        if(pos==nums.length)
        {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        backtrack(res,comb,nums,pos+1,false);
        if(!visit && pos>0 && nums[pos]==nums[pos-1])
            return;
        comb.add(nums[pos]);
        backtrack(res,comb,nums,pos+1,true);
        comb.remove(comb.size()-1);
    }
}
