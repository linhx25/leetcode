/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {

        char operation = '+';
        stack<int> stk;
        int currN = 0;
        for (int i=0; i<s.size(); i++){
            char c = s[i];
            if (isdigit(c))
                currN = currN * 10 + (c - '0');
            if (!isdigit(c) && !isspace(c) || i == s.size()-1){
                if (operation=='+')
                    stk.push(+currN);
                else if (operation=='-')
                    stk.push(-currN);
                else if (operation=='*'){
                    int n = stk.top();
                    stk.pop();
                    stk.push(n * currN);
                }
                else{
                    int n = stk.top();
                    stk.pop();
                    stk.push(n / currN);
                }
               currN = 0;
               operation = c;
            }
        }
        int res = 0;
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};
// @lc code=end

