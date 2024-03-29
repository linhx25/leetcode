/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; // sum_subarr: count
        int count = 0, sum = 0;
        
        m[0] = 1;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            count += m[sum - k];
            m[sum]++;
        }
        return count;
    }
};
// @lc code=end

