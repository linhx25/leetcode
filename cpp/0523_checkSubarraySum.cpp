// dp+hash
// 用dp[i]表示[0:i]闭区间的和，则任意[i:j]闭区间的和表示为
// dp[j],i==0
// dp[j]-dp[i-1],i>0
// （1）暴力：
// 对于每一个位置j，检查j之前的所有位置是否有可以整除k的子数组
// （2）Hash：(太难了。。。)
// 设位置 j < i : 
// 0 到 j 的前缀和 preSum1 = 某常数1 * k + 余数1
// 0 到 i 的前缀和 preSum2 = 某常数2 * k + 余数2
// 当找到 余数1 等于 余数2时， 则 j + 1 到 i 的连续和 = preSum2 - preSum1 = (某常数2 - 某常数1) * k， 必为 k 的倍数， 返回true
// 我们不仅要记录某个数(mod k条件下)是否出现过，还需要记录它的出现位置，以保证这个数组长度至少为2
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sum = sum%k;
            if(m.count(sum))
            {
                if(i-m[sum]>=2)
                    return true;
            }
            else
                m[sum] = i;
        }
        return false;
    }
};
