class Solution {
    public boolean isPalindrome(int x) {
        if(x<0 || x%10==0&&x!=0)
            return false;
        int rev_x = 0;
        while(rev_x<x)
        {
            rev_x = rev_x*10 + x%10;
            x /= 10;
        }
        return rev_x==x || rev_x/10==x;
    }
}
