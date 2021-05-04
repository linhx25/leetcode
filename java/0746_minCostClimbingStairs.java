class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int ppre=0,pre=0;
        for(var i=2;i<cost.length+1;i++)
        {
            int cur = Math.min(pre+cost[i-1],ppre+cost[i-2]);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
}
