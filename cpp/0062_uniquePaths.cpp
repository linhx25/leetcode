// 直接用组合计算。。。。
// 对于m*n的网格，只需要移动m-1次右移，n-1次下移即可到达终点，
// 于是答案应该是C_{m+n-2}^{m-1} = [(m+n-2)(m+n-3)...(n)]/[(m-1)(m-2)...1]
// 这里做一些小优化，因为分子和分母总共有m-1项或n-1项，因此可以并行，将时间复杂度降低
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res=1;
        if(n<m)
            swap(m,n);
        for(int i=n,j=1;j<m;i++,j++)
            res = res*i/j;
        return res;
    }
};
