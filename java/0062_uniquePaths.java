class Solution {
    public int uniquePaths(int m, int n) {
        long res =1;
        if(n<m)
        {
            int tmp =m;
            m=n;
            n=tmp;
        }
        for(int i=n,j=1;j<m;i++,j++)
            res = res*i/j;
        return (int)res;
    }
}
