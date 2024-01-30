/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */


// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        // stripping
        size_t start = s.find_first_not_of(' ');
        if (start == -1) return false;
        size_t end = s.find_last_not_of(' ');
        s = s.substr(start, end - start + 1);
        
        // states
        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        for (auto i = 0; i < s.size(); i++){
            char c = s[i];
            if (c == '+' || c == '-'){
                if (i!=0 && s[i-1]!='e' && s[i-1]!='E') return false;
            }
            else if (c == '.'){
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (c == 'E' || c == 'e'){
                if (!numSeen || eSeen) return false;
                numSeen = false; // digit must be seen after E/e
                eSeen = true;
            }
            else if (isdigit(c)){
                numSeen = true;
            }
            else return false;
        }
        return numSeen;
    }
};
// @lc code=end

