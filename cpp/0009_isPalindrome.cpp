// 1.edge: 负数、个位为0
// 2.建立一个反转数reverted_x，同时减少x的位数，增加反转数的位数：
// 只需反转一半，x>reverted_x的情况
// 每次reverted_x = reverted_x *10(反转数字进一位)） + x%10(个位； x = x/10；
// 最后当reverted_x==x（偶数）或者reverted_x/10==x（奇数）时就是回文数
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x%10==0&&x!=0)
            return false;
        int rev_x=0;
        while(rev_x<x)
        {
            rev_x = rev_x*10+x%10;
            x/=10;
        }
        return rev_x==x || rev_x/10==x;
    }
};
