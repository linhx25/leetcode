// 1.Hash, 但空间占O(n)
// 2.Vote： 维护一个count，实时更新众数，因为众数一定会剩下，所以count>0的数即为众数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res;
        for(int num:nums)
        {
            if(count==0)
                res = num;
            count += res==num? 1 : -1;
        }
        return res;
    }
};
