// dp[step][i]表示第step步第i个位置的次数
// step=0,dp[step][0]=1,else dp[step][i]= 0
// 1<=step<=steps,dp[step][i]=dp[step-1][i-1]+dp[step-1][i]+dp[step-1][i+1]
// 注意溢出的问题，以及当steps<arrLen时不需要建立长度为arrLen的数组
class Solution {
public:
    int numWays(int steps, int arrLen) {
        if(arrLen==1)
            return steps;
        const int M = 1000000007;
        vector<int> arr(min(steps,arrLen));
        arr[0] = 1;
        for(int s=1;s<=steps;s++)
        {
            // 空间更节省的写法
            int tmp = arr[0],tmp2 = arr[0];
            arr[0] = (tmp+arr[1])%M;
            tmp = tmp2;
            for(int i =1;i<min(steps,arrLen)-1;i++)
            {
                tmp2 = arr[i];
                arr[i] = ((tmp+arr[i])%M+arr[i+1])%M;
                tmp = tmp2;
            }
            arr[min(arrLen,steps)-1] = (tmp+arr[min(arrLen,steps)-1])%M;
            
            // 原始写法
            // vector<int> tmp(min(steps,arrLen));
            // tmp[0] = (arr[0]+arr[1])%M;
            // for(int i=1;i<min(steps,arrLen)-1;i++)
            //     tmp[i] = ((arr[i-1]+arr[i])%M+arr[i+1])%M;
            // tmp[min(steps,arrLen)-1] = (arr[min(steps,arrLen)-1]+arr[min(steps,arrLen)-2])%M;
            // arr = tmp;
        }
        return arr[0];
    }
};
