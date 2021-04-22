// 快慢指针，一个指针表示待交换的位置，另一个指针寻找下一个需要交换的非零元素
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        auto p1 = nums.begin();
        while(p1<nums.end() && *p1!=0)
            p1++;
        auto p2 = p1;
        while(p2<nums.end())
        {
            while(p2<nums.end() && *p2==0)
                p2++;
            if(p2==nums.end())
                break;
            swap(*p1,*p2);
            p1++;p2++;
        }
    }
};
