class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int x) {
        int maxIncrease=0,sat=0;
        for(int i=0;i<customers.length;i++)
        {
            maxIncrease -= customers[i];
            if(grumpy[i]==0)
                sat += customers[i];
        }
        if(x>=customers.length)
            return -maxIncrease;
        int increase = 0;
        for(int i=0;i<x;i++)
            increase += customers[i]*grumpy[i];
        maxIncrease = increase;
        for(int i=x;i<customers.length;i++)
        {
            increase = increase-customers[i-x]*grumpy[i-x]+customers[i]*grumpy[i];
            maxIncrease = Math.max(maxIncrease,increase);
        }
        return sat+maxIncrease;
    }
}
