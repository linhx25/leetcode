class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length()>s2.length())
            return false;
        int p2=0,diff=0;
        var arr = new int[26];//s1-s2
        while(p2<s1.length())
        {
            arr[s1.charAt(p2)-'a']++;
            arr[s2.charAt(p2)-'a']--;
            p2++;
        }
        for(var it:arr)
            if(it!=0)
                diff++;
        if(diff==0)
            return true;
        while(p2<s2.length())
        {
            if(s2.charAt(p2)!=s2.charAt(p2-s1.length()))
            {
                if(arr[s2.charAt(p2)-'a']==0)
                    diff++;
                arr[s2.charAt(p2)-'a']--;
                if(arr[s2.charAt(p2)-'a']==0)
                    diff--;

                if(arr[s2.charAt(p2-s1.length())-'a']==0)
                    diff++;
                arr[s2.charAt(p2-s1.length())-'a']++;
                if(arr[s2.charAt(p2-s1.length())-'a']==0)
                    diff--;
                if(diff==0)
                    return true;
            }
            p2++;
        }
        return false;
    }
}
