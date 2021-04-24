class Solution {
    public int[] sortArray(int[] nums) {
        partition(nums,0,nums.length-1);
        return nums;
    }
    public void partition(int[] nums,int left,int right)
    {
        if(left>=right)
            return;
        int storeIdx = new Random().nextInt(right-left + 1) + left;
        var tmp = nums[storeIdx];
        nums[storeIdx] = nums[right];
        nums[right] = tmp;
        
        storeIdx = left;
        for(var p=left;p<right;p++)
        {
            if(nums[p]<nums[right])
            {
                tmp = nums[p];
                nums[p] = nums[storeIdx];
                nums[storeIdx] = tmp;
                storeIdx++;
            }
        }
        tmp = nums[right];
        nums[right] = nums[storeIdx];
        nums[storeIdx] = tmp;

        partition(nums,storeIdx+1,right);
        partition(nums,left,storeIdx-1);
    }
}
