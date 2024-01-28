/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, bal = 0;
        for (auto c:s){
            bal += c == '(' ? 1: -1; // s[i] is either '(' or ')'.
            if (bal < 0){
                ans++;
                bal++;
            }
        }
        return ans + bal;
    }
};
// @lc code=end

