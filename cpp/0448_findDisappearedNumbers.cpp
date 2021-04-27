// 1.类似0041，遍历2遍数组：
// （1）先标记在目标范围内的数加负号（如果已经标记，则不加）
// （2）再遍历将未标记的数加入返回的结果数组
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] *= -1;
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                res.push_back(i+1);
        return res;
    }
};
