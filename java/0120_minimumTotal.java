// list 可能会比数组慢很多
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size()<2)
            return triangle.get(0).get(0);
        List<List<Integer>> dp = new ArrayList<List<Integer>>(2);
        dp.add(new ArrayList<Integer>(Arrays.asList(triangle.get(0).get(0))));
        dp.add(new ArrayList<Integer>());

        for(var row=1;row<triangle.size();row++)
        {
            for(var col=0;col<triangle.get(row).size();col++)
            {
                if(col==0)
                    dp.get(1).add(dp.get(0).get(col)+triangle.get(row).get(col));
                else if(col==triangle.get(row).size()-1)
                    dp.get(1).add(dp.get(0).get(col-1)+triangle.get(row).get(col));
                else 
                    dp.get(1).add(Math.min(dp.get(0).get(col),dp.get(0).get(col-1)) +triangle.get(row).get(col));
            }
            dp.remove(0);
            dp.add(new ArrayList<Integer>());
        }
        int res = dp.get(0).get(0);
        for(var i=1;i<dp.get(0).size();i++)
            if(dp.get(0).get(i)<res)
                res = dp.get(0).get(i);
        return res;
    }
}
