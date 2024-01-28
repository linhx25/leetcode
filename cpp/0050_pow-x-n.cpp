/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 11 = 1011 = 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 1
 7^11 = 7^(2^3) * 7^(2^1) * 7^(2^0)
*/
// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long N = n;  // Use long long to handle negation of INT_MIN

        if (N < 0){
            x = 1 / x;
            N = -N;
        }
        
        while (N!=0){
            // if the last bit is 1 (binary)
            if ((N & 1) == 1) res *= x;
            x *= x; // right shift (7^1 -> 7^2)
            N = N>>1;
        }
        return res;
    }
};
// @lc code=end

