// 魔鬼hash+链表联想，很难的一道题，要培养这种思维
// 可以把链表的next看成是一种数组的hash映射，这样寻找重复的值，等价于寻找重复的映射，即环，然后直接照抄142的解法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1=0,p2=0;
        while(true)
        {
            p2 = nums[nums[p2]];
            p1 = nums[p1];
            if(p2==p1)
            {
                p1=0;
                while(p1!=p2)
                {
                    p2 = nums[p2];
                    p1 = nums[p1];
                }
                return p1;
            }
        }
    }
};
