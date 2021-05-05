class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        backtrack(res,comb,candidates,target,0);
        return res;
    }
    public void backtrack(List<List<Integer>> res, List<Integer> comb, int[] candidates,int target,int idx)
    {
        if(idx>=candidates.length)
            return;
        if(target==0)
        {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        if(target-candidates[idx]>=0)
        {
            comb.add(candidates[idx]);
            backtrack(res,comb,candidates,target-candidates[idx],idx);
            comb.remove(comb.size()-1);
        }
        else
            return;
        backtrack(res,comb,candidates,target,idx+1);
    }
}
