// 遍历数组，每次维护一个最远可达距离dist：
// 1.如果dist超过数组长，返回true
// 2.如果当前位置可达，则比较当前位置的dist和历史dist
// 3.如果当前位置不可达（大于dist），则返回false
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist=0;
        for(auto i=0;i<nums.size();i++)
        {
            if(dist>=nums.size()-1)
                return true;
            if(i<=dist)
                dist = max(dist,i+nums[i]);
            else    
                return false;
        }
        return false;
    }
};
