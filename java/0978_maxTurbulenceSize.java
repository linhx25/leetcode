class Solution {
    public int maxTurbulenceSize(int[] arr) {
        if(arr.length<2)
            return 1;
        else if(arr.length==2 && arr[0]!=arr[1])
            return 2;
        int right=1,left=0,res=1;
        while(right<arr.length-1)
        {
            if((arr[right]<arr[right+1]&&arr[right]<arr[right-1])||(arr[right]>arr[right+1]&&arr[right]>arr[right-1]))
                right++;
            else
                left = right++;
            if(!(left==right-1 && arr[left]==arr[right]))
                res = Math.max(res,right-left+1);
        }
        return res;
    }
}
