/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int maxidx = str.size()-1, left=-1, right=-1;
        for (int i=str.size()-1; i>=0; i--){
            if (str[i] > str[maxidx])
                maxidx = i;
            if (str[i] < str[maxidx]){
                left = i;
                right = maxidx;
            }
        }
        if (left != -1)
            swap(str[left], str[right]);
        return stoi(str);
    }
};
// @lc code=end

