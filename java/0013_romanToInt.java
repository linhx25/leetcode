class Solution {
    public int romanToInt(String s) {
        int res=0;
        int pre = getValue(s.charAt(0));
        for(int i=1;i<s.length();i++)
        {
            int next = getValue(s.charAt(i));
            if(pre>=next)
                res+=pre;
            else
                res-=pre;
            pre = next;
        }
        return res+pre;
    }
    public int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
}
