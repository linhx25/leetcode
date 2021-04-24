class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums,0,nums.length-1);
        return nums;
    }
    public void mergeSort(int[] nums, int left, int right)
    {
        if(left>=right)
            return;
        int mid = (left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);

        var arr = new ArrayList<Integer>();
        int p1=left,p2=mid+1;
        while(p1<=mid && p2<=right)
        {
            if(nums[p1]>nums[p2])
                arr.add(nums[p2++]);
            else
                arr.add(nums[p1++]);
        }
        while(p2<=right)
            arr.add(nums[p2++]);
        while(p1<=mid)
            arr.add(nums[p1++]);
        for(p1=left;p1<=right;p1++)
            nums[p1] = arr.get(p1-left);
    }
}
