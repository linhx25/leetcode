// t 是 s 的异位词等价于「两个字符串排序后相等」
// 先建立一个hashmap，遍历t得到char-freq，再遍历t减去freq
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> arr(26,0);
        
        for(auto &c:s)
            arr[c-'a']++;
        
        for(auto &c:t)
        {
            arr[c-'a']--;
            if(arr[c-'a']<0)
                return false;
        }
        return true;
    }
};
