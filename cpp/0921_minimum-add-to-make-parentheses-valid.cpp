/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n_added = 0, bal = 0; 
        for (auto c:s){
            bal += c == '(' ? 1: -1; // s[i] is either '(' or ')'.
            if (bal < 0){
                n_added++;
                bal++;
            }
        }
        return n_added + bal;
    }
};
// @lc code=end

