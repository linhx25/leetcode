/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool helper(string s, int left, int right){
        while (left <= right){
            if (s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left <= right){
            if (s[left] == s[right]){
                left ++;
                right--;
            }
            else{
                break;
            }
        }
        bool case1 = helper(s, left, right - 1);
        bool case2 = helper(s, left + 1, right);
        return (case1 || case2);
    }
};
// @lc code=end

