class Solution {
    public int characterReplacement(String s, int k) {
        if(s.length()<k)
            return s.length();
        int p1=0,p2=0,res=0,maxCount=0;
        var arr = new int[26];
        while(p2<s.length())
        {
            arr[s.charAt(p2)-'A']+=1;
            maxCount = Math.max(maxCount,arr[s.charAt(p2)-'A']);
            if(p2-p1+1-maxCount>k)
            {
                arr[s.charAt(p1)-'A']--;
                p1++;
            }
            res = Math.max(res,++p2-p1);
        }
        return res;
    }
}
