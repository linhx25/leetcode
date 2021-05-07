class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        backtrack(res,comb,n,1,k);
        return res;
    }
    public void backtrack(List<List<Integer>> res, List<Integer> comb, int n,int pos,int k)
    {
        if(comb.size()==k)
        {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        for(int i=pos;i<=n;i++)
        {
            comb.add(i);
            backtrack(res,comb,n,i+1,k);
            comb.remove(comb.size()-1);
        }
    }
}
