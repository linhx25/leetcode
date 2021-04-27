class Solution {
    public int lengthOfLongestSubstring(String s) {
        int p1=0,p2=0,res=0;
        var m = new HashSet();
        while(p2<s.length())
        {
            while(m.contains(s.charAt(p2)))
                m.remove(s.charAt(p1++));
            m.add(s.charAt(p2++));
            res = Math.max(res,p2-p1);
        }
        return res;
    }
}
