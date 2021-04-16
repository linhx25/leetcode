// 双指针，左指针代表待修改的位置，右指针代表修改的值。O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        auto p1=nums.begin();
        auto p2=p1+1;
        while(p2!=nums.end())
        {
            while(p2!=nums.end() && *p2 == *(p2-1))
                p2++;
            if(p2==nums.end())
                break;
            *(++p1) = *p2;
            p2++;
        }

        return p1-nums.begin()+1;
    }
};
