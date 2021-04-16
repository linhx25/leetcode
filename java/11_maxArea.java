class Solution {
    public int maxArea(int[] height) {
        var p1=0;
        var p2=height.length-1;
        var res = (p2-p1) * Math.min(height[p1],height[p2]);
        var t=0;
        while(p1 != p2-1)
        {
            if(height[p1]>height[p2])
            {
                if(height[p2]<height[p2-1])
                {
                    t=(p2-1-p1)*Math.min(height[p1],height[p2-1]);
                    res = Math.max(t,res);
                }
                p2--;
            }
            else
            {
                if (height[p1+1]>height[p1])
                {
                    t=(p2-p1-1)*Math.min(height[p1+1],height[p2]);
                    res=Math.max(t,res);
                }
                p1++;
            }
        }
        return res;
    }
}
