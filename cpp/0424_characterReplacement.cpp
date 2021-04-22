// 最长子串=连续，用sliding window
// gan, 太难了
// 用一个数组来记录1-26个字符出现的次数
// while p2 未到最右
// 左指针何时右移：当窗口长度-窗口内字符最大出现次数>k
// 更新数组
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26);
        int p1=0,p2=0,res=0,maxCount = 0;
        while(p2<s.length())
        {
            arr[s[p2]-'A'] += 1;
            maxCount = max(maxCount,arr[s[p2]-'A']);
            if(p2-p1+1-maxCount>k)
            {
                arr[s[p1]-'A']--;
                p1++;
            }
            res = max(res,++p2-p1);
        }
        return res;
    }
};
