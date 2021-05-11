// 直接用hashtable存储字符-出现次数，再次遍历得到坐标即可
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(char &c:s)
        {
            if(m.count(c))
                m[c]++;
            else
                m.insert({c,1});
        }
        for(int i=0;i<s.size();i++)
            if(m[s[i]]==1)
                return i;
        return -1;
    }
};
