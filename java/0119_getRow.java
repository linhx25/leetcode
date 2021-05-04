class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<Integer>(Arrays.asList(new Integer[++rowIndex]));
        long comb = 1;
        res.set(0,1);
        res.set(rowIndex-1,1);
        for(int i=1,j=rowIndex-1;i<(rowIndex/2+rowIndex%2);i++,j--)
        {
            comb = comb*j/i;
            res.set(i,(int)comb);
            res.set(rowIndex-1-i,(int)comb);
        }
        return res;
    }
}
