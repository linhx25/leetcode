#include <map>
using namespace std;
// 1.brute force需要O(n2)的遍历
// 2.思路是一次遍历储存下已经遍历的值，在这些值里查找就可以避免重复遍历

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> Map;
        vector<int> res;
        typedef pair<int,int> p;

        auto item_i = nums.at(0);
        Map.insert(p(item_i,0));

        for (auto j=1; j<nums.size();j++)
        {
            if (nums[j]==target-item_i)
            {
                res={0,j};
                break;
            }
            else
            {
                if (Map.count(target-nums[j])>0)
                {
                    res = {j,Map.at(target-nums[j])};
                    break;
                }
                Map.insert(p(nums[j],j));
            }
        }
        return res;
    }
};
