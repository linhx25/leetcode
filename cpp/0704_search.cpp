// Binary Search：
// 初始：left=0，right=size
// 循环条件：left<right
// 更新：使用左闭右开[left,mid],(mid,right]
// 返回：如果查找得到：（1）位置一定在区间内（2）target值与该位置的值相等，反之返回-1；
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p1=0,p2 = nums.size();
        while(p1<p2)
        {
            int mid = (p1+p2)>>1;
            if(nums[mid]>=target)
                p2 = mid;
            else
                p1 = mid+1;
        }
        return p1<nums.size() && nums[p1]==target?p1:-1;
    }
};
