/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        if (k==1) return true;

        int sum = 0;
        unordered_map<int, int> m; // subarr sum remainder: index
        m[0] = -1;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            sum = sum % k;
            if(m.count(sum)){
                if (i - m[sum] > 1) // since m[0]=-1, need to handle it
                    return true;
            }
            else
                m[sum] = i;
        }
        return false;
    }
};
// @lc code=end

