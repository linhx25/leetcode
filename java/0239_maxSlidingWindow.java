class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        var max_heap = new PriorityQueue<int[]>(new Cmp());
        int[] res = new int[nums.length-k+1];
        for(var i=0;i<k-1;i++)
            max_heap.add(new int[]{nums[i],i});
        for(int i=0;i<=nums.length-k;i++)
        {
            max_heap.add(new int[]{nums[i+k-1],i+k-1});
            while(i>max_heap.peek()[1])
                max_heap.poll();
            res[i] = max_heap.peek()[0];
        }
        return res;
    }
}
class Cmp implements Comparator<int[]>
{
    public int compare(int[] p1,int[]p2)
    {
        return p1[0] != p2[0] ? p2[0] - p1[0] : p2[1] - p1[1];
    }
}
