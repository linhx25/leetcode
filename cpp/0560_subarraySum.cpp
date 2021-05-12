// 暴力：每个位置往前搜索，得到该位置的和为k的连续子数组有多少，遍历所有位置得到和
// hash实在太难了。。。。
// dp+Hash：对于一个dp[i]:定义为【0，i】的和，则任意【i，j】的和表示为
// dp[j],i==0
// dp[j] - dp[i-1],i>0
// 从而当连续子数组和为k时，有dp[j]-k = dp[i-1]
// 从而可以用一个hash记录所有dp[i-1]出现的次数，即 dp[j]-k 出现的次数，即和为k的子数组在之前出现的次数
// 此外，dp[i] = dp[i-1]+nums[i]
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre=0,res=0;
        map<int,int> m; // value - counts
        m[0] = 1;
        for(auto i=0;i<nums.size();i++)
        {
            pre = pre+nums[i];
            if(m.count(pre-k))
                res+=m[pre-k];
            m[pre]++;
        }
        return res;
    }
};
