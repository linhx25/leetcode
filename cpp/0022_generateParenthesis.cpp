// 太难了。。。。
// 重点是要理解递归生成字符串
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("",res,n,n);
        return res;
    }
    void backtrack(string s, vector<string> &res, int left, int right)
    {
        // 已经达到生成的长度
        if(left==0 && right==0)
        {
            res.push_back(s);
            return;
        }
        // 如果左括号数等于右括号数，只能加左括号
        if(left==right)
            backtrack(s+"(",res,left-1,right);
        // 否则，可以加左括号也可以加右括号
        else 
        {
            if(left>0)
                backtrack(s+"(",res,left-1,right);
            backtrack(s+")",res,left,right-1);
        }
    }
};
