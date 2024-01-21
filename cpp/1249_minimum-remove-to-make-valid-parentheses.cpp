/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
    string helper(string s, char left, char right){
        int cnt = 0;
        string res;
        for (auto c : s){
            if (c == left){
                cnt++;
            }
            if (c == right){
                if (cnt == 0){
                    continue;
                }
                cnt--;
            }
            res += c;
        }
        return res;
    }
public:
    string minRemoveToMakeValid(string s) {
        auto res = helper(s, '(', ')');
        reverse(res.begin(), res.end());
        res = helper(res, ')', '(');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

