// C_k^i = k!/[(k-i)!i!] = [k(k-1)...(k-i+1)]/i!
// 参考0062求组合数的方法,只算这一行即可
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(++rowIndex);
        long long comb = 1;
        // i & rowIndex-1-i是对称的
        res[0] = 1;
        res[rowIndex-1]=1;
        // 因为对称，只需要算到一半就可以
        for(auto i=1,j=rowIndex-1;i<(rowIndex/2+rowIndex%2);i++,j--)
        {
            comb = comb*j/i;
            res[i]= (int)comb;
            res[rowIndex-1-i]= (int)comb;
        }
        return res;
    }
};
