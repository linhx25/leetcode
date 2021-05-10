// 使用一个hashmap 存储所有的mapping字符串，回溯遍历即可
// ...好难,字符串的题都很不友好
class Solution {
    map<char, string> m
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        
        vector<string> res;
        string comb = "";
        backtrack(res,comb,0,digits);
        return res;
    }
    void backtrack(vector<string> &res,string &comb,int pos,string digits)
    {
        if(comb.size()==digits.size())  
        {
            res.push_back(comb);
            return;
        }
        string letters = m[digits[pos]];
        for(int i=0;i<letters.size();i++)
        {
            comb += letters[i];
            backtrack(res,comb,pos+1,digits);
            comb.pop_back();
        }
    }
};
