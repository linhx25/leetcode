class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        backtrack(res,comb,nums,0);
        return res;
    }
    public void backtrack(List<List<Integer>> res, List<Integer> comb,int[]nums,int pos)
    {
        if(pos==nums.length)
        {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        comb.add(nums[pos]);
        backtrack(res,comb,nums,pos+1);
        comb.remove(comb.size()-1);
        backtrack(res,comb,nums,pos+1);
    }
}
