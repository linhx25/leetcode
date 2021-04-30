class Solution {
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        for(var i=0;i<s.length();i++)
        {
            if(!stk.empty() && isPairChar(stk.peek(),s.charAt(i)))
                stk.pop();
            else 
                stk.push(s.charAt(i));
        }
        return stk.empty();
    }
    public boolean isPairChar(char a, char b)
    {
        if(a=='('&& b==')' || a=='['&& b==']' || a=='{'&& b=='}')
            return true;
        else
            return false;
    }
}
