#include <map>
#include <string>
using namespace std;

// sliding window: 右指针检测到超过2个不同字符就停下，这样左闭右开的区间是一个当前取到的最长子串
// 左指针向右移动，直到只剩一个字符
// 用一个字典来存储 字符-字符出现次数
// 终止条件：右指针到了最右（因为求最长，不需要再考虑左指针了）
class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        if(s.length()<2)
            return s.length();
        int p1=0,p2=1,res=0;
        map<char,int> m;
        m[s[p1]] = 1;
        while(p2<s.length())
        {
            while(p2<s.length() && m.size()<=2)
                m[s[p2++]]++;
            res = max(res,p2-p1);
            while(p1<s.length() && m.size()>2)
            {
                if(m[s[p1]]!=0)
                    m[s[p1++]]--;
                else
                    m.erase(s[p1++]);
            }  
        }
        return res;
    }
    
};