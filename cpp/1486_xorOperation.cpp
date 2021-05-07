// x^x=0；
// x^y = y^x（交换律）；
// (x^y)^z = x^(y^z) (结合律）；
// x^y^y=x（自反性）；
// for all i in Z, 有 4i^(4i+1)^(4i+2)^(4i+3)=0
// 把start+2i化为连续异或
class Solution {
public:
    int xorOperation(int n, int start) {
        // 只有当n和start都为奇数，连续异或的结果最后一位才为1
        int place = (int)(n%2==1&&start%2==1);
        int res = start>>1;
        res = sumXOR(res-1) ^ sumXOR(res+n-1);
        res = (res<<1)+place; 
        return res;
    }
    int sumXOR(int x)
    {
        // 计算[1..x]连续的xor结果
        if(x%4==0)
            return x;
        else if(x%4==1)
            return 1;
        else if(x%4==2)
            return x+1;
        else 
            return 0;
    }
};
