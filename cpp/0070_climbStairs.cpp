// 1.dp: f(n) = f(n-1)+f(n-2)
// 2.推通项公式。。。1/sqrt(5) * (([1+sqrt(5)]/2)**n +([1-sqrt(5)]/2)**n)
class Solution {
public:
    int climbStairs(int n) {
        int p1=0,p2=0,p3=1;//base
        for(auto i=0;i<n;i++)
        {
            p1 = p2;
            p2 = p3;
            p3 = p1+p2;
        }
        return p3;
    }
};
