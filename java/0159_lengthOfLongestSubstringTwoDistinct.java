import String;
class Solution
{
    public int lengthOfLongestSubstringTwoDistinct(String s)
    {
        if(s.length()<2)
            return s.length();
        int p1=0,p2=1,res=0;
        var map = new HashMap<Integer,Integer>();
        map.put(s[p1],1);
        while(p2<s.length())
        {
            while(p2<s.length() && map.size()<=2)
                map.get(s[p2++]) += 1;
            res = Math.max(res,p2-p1);
            while(p1<s.length() && map.size()>2)
            {
                if(map.get(s[p1])>0)
                    map.get(s[p1++])--;
                else
                    map.pop(s[p1++]);
            }
        }
        return res;
    }
}

