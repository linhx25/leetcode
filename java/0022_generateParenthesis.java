class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack("",res,n,n);
        return res;
    }
    public void backtrack(String s, List<String> res,int left,int right)
    {
        if(left==0&&right==0)
        {
            res.add(s);
            return;
        }
        if(left==right)
            backtrack(s+"(",res,left-1,right);
        else
        {
            if(left>0)
                backtrack(s+"(",res,left-1,right);
            backtrack(s+")",res,left,right-1);
        }
    }
}
