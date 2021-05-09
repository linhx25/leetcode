// 先遍历一般数组，用字典记录value：出现次数，起始，终止；
// 再遍历字典，对出现次数最多的元素，对比长度，取最小的作为结果
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,vector<int>> m; // value, [count,start,end]
        for(auto i=0;i<nums.size();i++)
        {
            if(m.count(nums[i])==0)
            {
                m.insert({nums[i],vector<int>(3,1)});
                m[nums[i]][1]=i;
                m[nums[i]][2]=i;
            }
            else
            {
                m[nums[i]][0]++;
                m[nums[i]][2]=i;
            }
        }
        int res = nums.size(),count=1;
        for(auto& [_,arr]:m)
        {
            if(arr[0]>count)
            {
                res = arr[2]-arr[1]+1;
                count = arr[0];
            }
            else if(arr[0]==count)
                res = min(res,arr[2]-arr[1]+1);
        }
        return res;
    }
};
