/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res(2);

        for (int i=0; i< nums.size(); i++){
            if(m.count(target - nums[i])){
                 res[0] = m[target - nums[i]];
                 res[1] = i;
                 break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

