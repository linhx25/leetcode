// merge sort
// 要领悟分而治之的思路：对于左右两个有序的数组，合并成一个有序的栈/数组只需要不断对比取小的数入栈/数组即可，类似0004;
// 如何获得左右两个有序的数组？先分，直到无法再分解的时候，单个元素必定是有序的，以此作为base case
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,(int)nums.size()-1);
        return nums;
    }
    void mergeSort(vector<int> & nums, int left, int right)
    {
        if(left>=right)
            return;
        int mid = (right+left)/2;
        // 对左右两边排序
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        // 左右已经有序，分别入栈/数组
        vector<int> arr;
        int p1=left,p2=mid+1;
        while(p1<=mid && p2<=right)
        {
            if(nums[p1]>nums[p2])
                arr.push_back(nums[p2++]);
            else
                arr.push_back(nums[p1++]);
        }
        while(p2<=right)
            arr.push_back(nums[p2++]);
        while(p1<=mid)
            arr.push_back(nums[p1++]);
        // arr已经有序，修改nums对应位置即可
        for(p1=left;p1<=right;p1++)
            nums[p1] = arr[p1-left];
    }
};
