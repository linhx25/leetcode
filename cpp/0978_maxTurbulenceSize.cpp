// sliding window:右指针正常右移，左指针主动右移（需判断条件）; 记res为最大长度
// 右指针：当符合湍流条件时，右移
// 左指针：当不符合湍流条件时，下一个可能出现的子数组一定在右指针位置之后，因此直接移动到和右指针相同的位置，右指针正常右移
// 特殊情况：经过上述移动后，左右指针相邻并且值一样，此时不需要更新res
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()<2)
            return arr.size();
        else if(arr.size()==2)
            return arr[0]==arr[1]?1:2;
        int res=1,right=1,left=0;
        while(right<arr.size()-1)
        {
            if((arr[right]>arr[right-1] && arr[right]>arr[right+1])||(arr[right]<arr[right-1] && arr[right]<arr[right+1]))
                right++;
            else
                left = right++;
            if(!(right==left+1 && arr[right]==arr[left]))
                res = max(res,right-left+1);
        }
        return res;
    }
};
