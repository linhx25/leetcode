class Solution {
    public int xorOperation(int n, int start) {
        int place = 0;
        if(n%2==1&&start%2==1)
            place =1;
        int res = start>>1;
        res = sumXOR(res-1)^sumXOR(res+n-1);
        res = res<<1 + place;
        return res;
    }
    public int sumXOR(int x)
    {
        if(x%4==0)
            return x;
        else if(x%4==1)
            return 1;
        else if(x%4==2)
            return x+1;
        else
            return 0;
    }
}
