// 1.BF: 先排序，再O(n2)+双指针遍历
#include <climits>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto res=nums[0]+nums[1]+nums[2];

        for (auto p=nums.begin();p<nums.end()-2;p++)
        {   
            auto p1=p+1;
            auto p2=nums.end()-1;
            while(p1<p2)
            {                
                if(abs(*p1 + *p2+ *p -target)<abs(res-target))
                    res = *p1 + *p2+ *p;

                if (*p1 + *p2+ *p > target)
                    p2--;
                else
                    p1++;
            }
        }
        return res;
    }
};
