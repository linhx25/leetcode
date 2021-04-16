// 1.BF：O(n3),为了使不重复，必须排序
// 2.太难了。。。判断不重复的条件很容易陷入边界的混乱。
// 3.因为有多个数的存在，容易想到双指针，关键在于判断每个数是否重复：下一位置的数和他相同
// 4.最左边的数(a)判断重复：用上一位置的数来比较

#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3)
            return res;

        sort(nums.begin(),nums.end());
        
        for(auto a=nums.begin();a!=nums.end()-2;a++)
        {   
            if (*a>0)
                break;
            if (a>nums.begin() && *a==*(a-1))
                continue;
            auto b = a+1;
            auto c = nums.end()-1;
            while(b<c)
            {
                if((*a + *b + *c)==0)
                {   
                    while(b<c && *b==*(b+1))
                        b++;
                    while(b<c && *c==*(c-1))
                        c--;
                    res.push_back({*a,*b,*c});
                    b++;
                    c--;
                }   
                else if ((*a + *b + *c)>0)
                    c--;
                else
                    b++;
            }
            
        }

        return res;
    }
};
