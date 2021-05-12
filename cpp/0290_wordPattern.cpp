// 2个hash，相同规律代表pattern到string之间存在双射
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size()>s.size())
            return false;
        map<char,string> m1;
        map<string,char> m2;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(count>=pattern.size())
                return false;
            string str = "";
            while(i<s.size() && s[i]!=' ')
                str+=s[i++];
            if(m1.count(pattern[count]))
            {
                if(m1[pattern[count]]!=str)
                    return false;
            }
            else
                m1.insert({pattern[count],str});
            if(m2.count(str))
            {
                if(m2[str]!=pattern[count])
                    return false;
            }
            else
                m2.insert({str,pattern[count]});
            count++;
        }  
        return count>=pattern.size();//注意：必须把pattern遍历完
    }
};
