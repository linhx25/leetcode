class Solution {
    public int numWays(int steps, int arrLen) {
        if(arrLen==1)
            return steps;
        final int M =1000000007;
        var res = new int[Math.min(steps,arrLen)];
        res[0] = 1;
        for(int s=1;s<=steps;s++)
        {
            int tmp=res[0],tmp2=res[0];
            res[0] = (tmp+res[1])%M;
            tmp = tmp2;
            for(int i=1;i<Math.min(steps,arrLen)-1;i++)
            {
                tmp2 = res[i];
                res[i] = ((tmp+res[i])%M+res[i+1])%M;
                tmp = tmp2;
            }
            res[Math.min(steps,arrLen)-1] = (tmp+res[Math.min(steps,arrLen)-1])%M;
        }
        return res[0];
    }
}
