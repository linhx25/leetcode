class Solution {
    public boolean isAnagram(String s, String t) {
        if(t.length()!=s.length())
            return false;
        int[] arr = new int[26];
        for(var i=0;i<s.length();i++)
            arr[s.charAt(i)-'a']++;
        for(var i=0;i<t.length();i++)
        {
            arr[t.charAt(i)-'a']--;
            if(arr[t.charAt(i)-'a']<0)
                return false;
        }
        return true;
    }
}
