// 用stack来匹配：如果入栈元素和栈顶元素相同，则都出栈；
// 如果不同，继续入栈直到遍历完string
// 如果最后栈为空，则有效
class Solution {
public:
    bool isValid(string s) {
        if(s.size() %2 !=0)
            return false;
        stack<char> stk;
        for(auto i=0;i<s.size();i++)
        {
            if(stk.size()>0 && isPairChar(stk.top(),s[i]))
                stk.pop();
            else
                stk.push(s[i]);
        }
        return stk.size()==0;
    }
    bool isPairChar(char a, char b)
    {
        if(a=='{' && b =='}' || a=='(' && b ==')' || a=='[' && b ==']')
            return true;
        else
            return false;
    }
};
