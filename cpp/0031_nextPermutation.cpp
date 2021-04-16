// 又一道好难的题。。。
// 解法很精妙，首先从后向前寻找第一个升序的元素，该元素为待交换的小数，该数后的序列降序；
// 接着从后向前查找第一个比该数大的数，交换，依然是降序；
// 最后用双指针反转降序序列，得到的即是所求的序列。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        auto p1 = nums.end()-2;
        while(p1>=nums.begin() && *p1>=*(p1+1))
            p1--;
        if(p1>=nums.begin())
        {
            auto p2 = nums.end()-1;
            while(p2>=p1 && *p1>=*p2)
                p2--;

            swap(*p1,*p2);
        }
        p1 = p1+1;
        auto p2 = nums.end()-1;
        while(p1<p2)
        {
            swap(*p1,*p2);
            p1++;p2--;
        }   
    }
};
