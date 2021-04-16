// 双指针，左指针用来找需修改的位置，右指针用来找待修改的值

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto p1=nums.begin();
        while(p1<nums.end() && *p1!=val)
            p1++;
        if(p1==nums.end())
            return nums.size();
        auto p2=p1;
        while(p2<nums.end())
        {
            while(p2<nums.end() && *p2==val)
                p2++;
            if(p2==nums.end())
                break;
            *(p1++) = *(p2++);
        }
        return p1-nums.begin();
    }
};
