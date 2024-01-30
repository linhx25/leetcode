/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (auto a=nums.begin(); a<nums.end()-2; a++){
            if(*a > 0) break;
            if(a > nums.begin() && *a == *(a-1)) continue;
            auto b = a + 1, c = nums.end()-1;
            while(b < c){
                if(*a + *b + *c == 0){
                    res.push_back({*a, *b, *c});
                    while(b<c && *b==*(b+1)) b++;
                    while(b<c && *c==*(c-1)) c--;
                    b++;
                    c--;
                }
                else if (*a + *b + *c > 0) 
                    c--;
                else 
                    b++;
            }
        }
        return res;
    }
};
// @lc code=end

