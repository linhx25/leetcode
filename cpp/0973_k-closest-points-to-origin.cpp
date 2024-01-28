/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    int distance(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }

    void quickSelect(vector<vector<int>>& points, int left, int right, int k){
        if (left >= right) return;
        // set pivot to the right
        int pivotIndex = rand() % (right - left + 1) + left;
        swap(points[pivotIndex], points[right]);
        auto pivotDistance = distance(points[right]);
        
        int slow = left;
        for (int fast=left; fast<right; fast++){
            if(distance(points[fast]) < pivotDistance){
                swap(points[fast], points[slow]);
                slow++;
            }
        }
        swap(points[slow], points[right]);

        int count = slow - left + 1;
        if(count == k) return;
        else if(count > k)
            quickSelect(points, left, slow - 1, k);
        else
            quickSelect(points, slow + 1, right, k - count);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand((unsigned)time(NULL));
        quickSelect(points, 0, points.size()-1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
// @lc code=end

