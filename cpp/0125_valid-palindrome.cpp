/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;
        while(left<right){
            while(left < right && !isalnum(s[left]) ) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(tolower(s[left])==tolower(s[right])){
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

