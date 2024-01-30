/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right){
        if(left>=right)
            return;
        // Randomly choose a pivot and swap it with the last element
        int pivotIndex = rand() % (right-left+1) + left;
        swap(nums[pivotIndex], nums[right]);
        
        int slow = left;
        for (int fast=left; fast<right; fast++){
            if(nums[fast]<nums[right]){
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
        swap(nums[slow], nums[right]);
        quickSort(nums, left, slow-1);
        quickSort(nums, slow+1, right);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

