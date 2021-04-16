// 1. 参考三数之和，改为三层循环+双指针达到O(n3)
#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        auto res = vector<vector<int>>();
        if(nums.size()<4)
            return res;

        sort(nums.begin(),nums.end());
        for(auto p1=nums.begin();p1<nums.end()-3;p1++)
        {
            if(nums.front()>target && target>=0)
                break;
            if(nums.back()<target && target<=0)
                break;
            if(p1>nums.begin() && *(p1-1)==*p1)
                continue;
            for(auto p2=p1+1;p2<nums.end()-2;p2++)
            {
                if(p2>p1+1 && *(p2-1)==*p2)
                    continue;
                auto p3 = p2+1;
                auto p4 = nums.end()-1;
                while(p3<p4)
                {
                    if(*p1+*p2+*p3+*p4 == target)
                    {
                        while(p3<p4 && *p3 ==*(p3+1))
                            p3++;
                        while(p3<p4 && *p4 ==*(p4-1))
                            p4--;
                        res.push_back({*p1,*p2,*p3,*p4});
                        p3++;p4--;
                    }
                    else if(*p1+*p2+*p3+*p4 > target)
                        p4--;
                    else
                        p3++;
                }
            }
        }
        return res;
    }
};
