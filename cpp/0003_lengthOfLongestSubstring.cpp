// 1.连续子串问题，习惯性sliding window
// 2.对于每一个左指针的元素，其对应右指针的最长子串是唯一的，而且右指针的位置总是在向右移动，不会回溯
// 3.因此可以用一个不排序的set（unordered_set）来记录已经有的字符，按顺序pop或put
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)
            return s.size();
        int p1=0,p2=0,res=0;
        unordered_set<char> record;
        while(p2<s.size())
        {
            // 判断p1是否需要右移
            while(record.count(s[p2])!=0)
                record.erase(s[p1++]);

            record.insert(s[p2++]);   
            res = max(res,p2-p1);
        }
        return res;
    }
};
