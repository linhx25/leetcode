class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        Arrays.sort(candidates);
        backtrack(candidates,res,comb,target,0);
        return res;
    }
    public void backtrack(int[] candidates,List<List<Integer>> res,List<Integer> comb,int target,int pos)
    {
        if(target==0)
        {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        for(var i=pos;i<candidates.length;i++)
        {
            if(target-candidates[i]<0)
                return;
            if(i>pos && candidates[i]==candidates[i-1])
                continue;
            comb.add(candidates[i]);
            backtrack(candidates,res,comb,target-candidates[i],i+1);
            comb.remove(comb.size()-1);
        }
    }
}
