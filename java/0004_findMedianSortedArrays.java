class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        var m = nums1.length;
        var n = nums2.length;
        if (n==0)
        {
            if (m%2==0)
            {
                return (double)(nums1[m/2-1]+nums1[m/2])/2;
            }
            else
            {
                return (double) nums1[m/2];
            }
        }
        if (m==0)
        {
            if (n%2==0)
            {
                return (double)(nums2[n/2-1]+nums2[n/2])/2;
            }
            else
            {
                return (double) nums2[n/2];
            }
        }
        var i=0;var j=0;
        var size = (m+n)/2 + 1;
        var vec_res = new int[size];
        for (var k=0;k<size;k++)
        {
            if (i!=m && j!=n)
            {
                if(nums1[i]>nums2[j])
                {
                    vec_res[k]=nums2[j];
                    j++;continue;
                }
                else
                {
                    vec_res[k]=nums1[i];
                    i++;continue;
                }
            }
            else
            {
                if (i!=m)
                {
                    vec_res[k]=nums1[i];
                    i++;continue;
                }
                if (j!=n)
                {
                    vec_res[k]=nums2[j];
                    j++;continue;   
                }
            }
        }
        if((m+n)%2==0)
        {
            var t = vec_res[vec_res.length-1];
            var tt = vec_res[vec_res.length-2];
            return ((double)(t+tt))/2;
        }
        else
        {
            return (double)(vec_res[vec_res.length-1]);
        }
    }
}
