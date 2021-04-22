// 连续升序的值，容易想到滑动窗口
// 如果窗口内求和小于target，右指针右移
// 如果窗口内求和大于target，左指针右移
// 如果等于，记录。
// 终止条件：p1 超过target的一半时，由于数组递增，因此不可能再有合适的解
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int p1=1,p2=2,sum=1;
        vector<vector<int>> res;
        while(p1<target/2+1)
        {
            if(sum<target)
                sum += p2++;
            else if(sum>target)
                sum -= p1++;
            else
            {
                vector<int> t;
                for(auto i=p1;i<p2;i++)
                    t.push_back(i);
                res.push_back(t);
                sum += p2++;
            }
        }
        return res;
    }
};