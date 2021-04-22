class Solution {
    public int[][] findContinuousSequence(int target) {
        int p1=1,p2=2,sum=1;
        List<int[]> res = new ArrayList<int[]>();
        while(p1<target/2+1)
        {
            if(sum>target)
                sum -= p1++;
            else if(sum<target)
                sum += p2++;
            else
            {
                var t = new int[p2-p1];
                for(var i=p1;i<p2;i++)
                    t[i-p1] = i;
                res.add(t);
                sum += p2++;
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}