class Solution {
    public int climbStairs(int n) {
        int p1=0,p2=0,p3=1;
        for(var i=0;i<n;i++)
        {
            p1=p2;
            p2=p3;
            p3=p1+p2;
        }
        return p3;
    }
}
