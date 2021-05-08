// 直接横向反复取交集
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(auto i=1;i<strs.size();i++)
            res = getCommon(strs[i],res);
        return res;
    }
    string getCommon(string s1,string s2)
    {
        string str="";
        for(int i=0;i<min(s1.length(),s2.length()) && s1[i]==s2[i];i++)
            str+=s1[i];
        return str;
    }
};
