class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        backtrack(res,comb,k,n,1);
        return res;
    }
    public void backtrack(List<List<Integer>> res, List<Integer> comb, int k, int target, int pos)
    {
        if(target==0 && comb.size()==k)
        {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        for(var i=pos;i<10;i++)
        {
            if(target-i<0 || comb.size()>k)
                return;
            comb.add(i);
            backtrack(res,comb,k,target-i,i+1);
            comb.remove(comb.size()-1);
        }
    }
}
