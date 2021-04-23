// 连续子数组，无脑sliding window
// 右指针主动右移，每次用一个key有序的container来存储出现次数
// 当container内key的极差大于limit时，左指针右移，同时更新container
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if(nums.size()==0)
            return 0;
        int p1=0,p2=0,res=0;
        map<int,int> m;
        while(p2<nums.size())
        {
            m[nums[p2]]++;
            while(p1<=p2 && m.rbegin()->first-m.begin()->first>limit)
            {
                m[nums[p1]]--;
                if(m[nums[p1]]==0)
                    m.erase(nums[p1]);
                p1++;
            }
            res = max(res,p2-p1+1);
            p2++;
        }
        return res;
    }
};
