// 利用前缀异或的性质（a^a)^b = b，不需要每次重复计算
// arr[left] ^...^ arr[right] = 
// [(arr[0]^...^arr[left-1]) ^ (arr[0]^...^arr[left-1])]^ (arr[left] ^...^ arr[right])=
// (arr[0]^...^arr[left-1]) ^ (arr[0]^...^arr[right])
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> record(arr.size()+1,0); // 0^num = num
        for(int i=0;i<arr.size();i++)
            record[i+1] = record[i]^arr[i];
        vector<int>res;
        for(int i=0;i<queries.size();i++)
            res.push_back(record[queries[i][0]]^record[queries[i][1]+1]);
        return res;
    }
};
