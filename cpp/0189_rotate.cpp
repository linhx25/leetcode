// 气死，原地hash的算法有一个edge case过不了，我觉得这测试用例有问题
// 直接reverse三次数组：
// (1)reverse整个数组
// (2)reverse[0,k]
// (3)reverse(k,size)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),k+nums.begin());
        reverse(nums.begin()+k,nums.end());
    }
};
