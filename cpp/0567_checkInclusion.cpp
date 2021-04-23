// 参考424，用一个数组储存1-26字符的出现次数
// BF：窗口固定长度，因此每次移动右指针，检查窗口内的字符出现次数和s1是否均一致
// 改进：bf做法多了很多重复的对比，用一个数组来记录数组和窗口内字符出现次数的差异，再用一个diff来表示总共差异的字符数，当diff为0时，就已经一致。
// 细节：每次移动窗口时，对窗口最右、最左的字符做检查：
// 1.如果该最右字符在数组内值为0，即没有差异，则因为新增导致diff+1；
// 2.因为新增一个字符，同时该字符在数组内值-1 （s1-s2就 减1，反之加1）
// 3.再次检查该字符在数组内的值，如果为0则说明diff-1
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        int p2=0,diff=0;
        vector<int> arr(26); // s1-s2
        while(p2<s1.size())
        {
            arr[s1[p2]-'a']+=1;
            arr[s2[p2]-'a']-=1;
            p2++;
        }
        for(int &it:arr)
            if(it!=0)
                diff++;
        if(diff==0)
            return true;
        while(p2<s2.size())
        {
            if(s2[p2]!=s2[p2-s1.size()])
            {
                if(arr[s2[p2]-'a']==0)
                    diff++;
                arr[s2[p2]-'a']--;
                if(arr[s2[p2]-'a']==0)
                    diff--;
                
                if(arr[s2[p2-s1.size()]-'a']==0)
                    diff++;
                arr[s2[p2-s1.size()]-'a']++;
                if(arr[s2[p2-s1.size()]-'a']==0)
                    diff--;
                
                if(diff==0)
                    return true;
            }
            p2++;
        }
        return false;
    }
};
