// 1.最简单做法：遍历一遍得到连乘，每个元素单独除一遍即可；
// 2.不能使用除法：
// （1）先遍历一遍，得到每个位置的左连乘（不包括该位置）
// （2）从右边开始遍历，获得右连乘，随后更新每个位置的左连乘
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int right=1;
        res[0]=1;
        for(auto i=1;i<nums.size();i++)
            res[i]=res[i-1]*nums[i-1];
        for(auto i=nums.size()-2;i>0;i--)
        {
            right*=nums[i+1];
            res[i]*=right;
        }
        res[0]=right*nums[1];
        return res;
    }
};
