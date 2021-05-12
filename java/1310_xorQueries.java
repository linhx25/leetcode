class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] record = new int[arr.length+1];
        for(int i=0;i<arr.length;i++)
            record[i+1] = record[i]^arr[i];
        int[] res = new int[queries.length];
        for(int i=0;i<queries.length;i++)
            res[i] = record[queries[i][0]]^record[queries[i][1]+1];
        return res;
    }
}
