class Solution {
    public boolean wordPattern(String pattern, String s) {
        if(s.length()<pattern.length())
            return false;
        Map<Character, String> m1 = new HashMap<>();
        Map<String,Character> m2 = new HashMap<>();
        int count = 0;
        for(var i=0;i<s.length();i++)
        {
            if(count>=pattern.length())
                return false;
            String str = "";
            while(i<s.length() && s.charAt(i)!=' ')
                str += s.charAt(i++);
            if(m1.containsKey(pattern.charAt(count)))
            {
                if(!(m1.get(pattern.charAt(count)).equals(str)))
                    return false;
            }
            else
                m1.put(pattern.charAt(count),str);
            if(m2.containsKey(str))
            {
                if(m2.get(str)!=pattern.charAt(count))
                    return false;
            }
            else
                m2.put(str,pattern.charAt(count));
            count++;
        }
        return count>=pattern.length();
    }
}
