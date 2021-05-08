class Solution {
    public String longestCommonPrefix(String[] strs) {
        String res = strs[0];
        for(int i=1;i<strs.length;i++)
            res = getCommon(res,strs[i]);
        return res;
    }
    public String getCommon(String s1,String s2)
    {
        String str = "";
        for(int i=0;i<Math.min(s1.length(),s2.length())&&s1.charAt(i)==s2.charAt(i);i++)
        {
            str+=s1.charAt(i);
        }
        return str;
    }
}
