// 连续，容易想到sliding window
// window内等于0的数小于k，右指针右移，大于k，左指针右移，等于k，记录长度
// 终止条件：右指针到达最右，因为求最大长度，左指针无需再移动了
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size()<=k)
            return nums.size();
        int res=0,count=0,p1=0,p2=0;
        while(p2<nums.size())
        {
            if(nums[p2]==0)
                count++;
            while(count>k)
            {
                if(nums[p1]==0)
                    count--;
                p1++;
            }
            res = max(res,p2-p1+1);
            p2++;
        }
        return res;
    }
};