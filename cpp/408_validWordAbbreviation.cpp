class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {

        int n_char = 0, digit = 0;
        for (auto c:abbr){
            if (isdigit(c)){
                if (c=='0' && digit==0){
                    return false;
                }
                digit = digit * 10 + c - '0';
            }
            else{
                n_char += digit;
                digit = 0;
                if (n_char >= word.size() || word[n_char] != c){
                    return false;
                }
                n_char++;
            }
        }
        return ((digit + n_char) == word.size());
    }
};
