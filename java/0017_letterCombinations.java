class Solution {
    Map<Character,String> map = new HashMap<Character,String>()
    {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        if(digits.length()==0)
            return res;
        backtrack(digits,res,0,"");
        return res;
    }
    public void backtrack(String digits,List<String> res,int pos,String comb)
    {
        if(comb.length()==digits.length())
        {
            res.add(comb);
            return;
        }
        String letters = map.get(digits.charAt(pos));
        for(int i=0;i<letters.length();i++)
        {
            backtrack(digits,res,pos+1,comb+letters.charAt(i));
        }
        
    }
}
