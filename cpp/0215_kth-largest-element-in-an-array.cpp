/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for (auto n : nums){
            minheap.push(n);
            if (minheap.size() > k)
                minheap.pop();
        }
        return minheap.top();
    }
};
// @lc code=end

