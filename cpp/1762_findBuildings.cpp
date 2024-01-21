// OJ: https://leetcode.com/problems/buildings-with-an-ocean-view/
// Time: O(N)
// Space: O(1)

class Solution {
public:
    vector<int> findBuildings(vector<int>& A) {
        vector<int> ans;
        if (!A.empty()){
            ans.push_back((int) A.size() - 1);
        }
        for (int i = A.size() - 2; i>=0; i--){
            if A[i] > A[ans.back()]{
                ans.push_back(i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};