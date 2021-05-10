// 倒序后遍历，H-index = argmin_index(value>=index)；
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int res = 0;
        while(res<citations.size() && citations[citations.size()-res-1]>res)
        {
            res++;
        }
        return res;
    }
};
