class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        res.add(new ArrayList<Integer>(Arrays.asList(1)));
        for(var row=1;row<numRows;row++)
        {
            res.add(new ArrayList<>(Arrays.asList(1)));
            for(var col=1;col<row;col++)
                res.get(row).add(res.get(row-1).get(col)+res.get(row-1).get(col-1));
            res.get(row).add(1);
        }
        return res;
    }
}
