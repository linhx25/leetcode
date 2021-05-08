// 动态维护一个最大堆，如果堆顶元素不在滑动窗口内，则移除
// 这里的堆储存一个pair<value,index>，代表值和该值在数组中的位置，用index来判断是否在窗口内
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> max_heap;
        for(int i=0;i<k-1;i++)
            max_heap.emplace(nums[i],i);
        vector<int> res;
        for(int i=0;i<=nums.size()-k;i++)
        { 
            max_heap.emplace(nums[i+k-1],i+k-1);
            while(max_heap.top().second<i)
                max_heap.pop();
            res.push_back(max_heap.top().first);
        }
        return res;
    }
};
