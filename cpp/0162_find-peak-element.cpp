/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left < right){
            int mid = left + (right-left) / 2;
            // Compare mid with the next element
            if(nums[mid] < nums[mid+1])
                left = mid + 1; // If the mid element is less than its right neighbor, peak must be to the right of mid
            else
                right = mid; // If the mid element is greater than its right neighbor, peak could be mid or to the left of mid
        }
        return left; // peak must exist
    }
};
// @lc code=end

