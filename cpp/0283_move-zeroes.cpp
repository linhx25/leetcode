/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZero=0, curr=0; curr<nums.size(); curr++){
            if(nums[curr] != 0){
                swap(nums[lastNonZero], nums[curr]);
                lastNonZero++;
            }
        }
    }
};
// @lc code=end

