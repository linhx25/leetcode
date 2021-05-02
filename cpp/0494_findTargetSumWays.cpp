// 1.暴力递归，类似0022生成括号，遍历数组不断生成正/负的数，直到达到数组长度，判断和是否相等
// 2.可以用dp。。
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res=0;
        find(nums,target,0,0,res);
        return res;
    }
    void find(vector<int>& nums, int target, int pos, int sum,int &res)
    {
        if(pos==nums.size())
        {
            if(sum == target)
                res++;
            return;
        }
        find(nums,target,pos+1,sum+nums[pos],res);
        find(nums,target,pos+1,sum-nums[pos],res);
    }
};
