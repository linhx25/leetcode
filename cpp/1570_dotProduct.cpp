class SparseVector {
public:
    vector<pair<int, int>> idx_value_pair;
    SparseVector(vector<int> &nums) {
        for (int i=0; i < nums.size(); i++){
            if (nums[i]!=0){
                idx_value_pair.push_back(make_pair(i, nums[i]));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i=0, j=0, res=0;

        while(i < idx_value_pair.size() && j < vec.idx_value_pair.size()){
            if (idx_value_pair[i].first < vec.idx_value_pair[j].first){
                i++;
            }
            else if (idx_value_pair[i].first > vec.idx_value_pair[j].first){
                j++;
            }
            else{
                res += idx_value_pair[i].second * vec.idx_value_pair[j].second;
                i++;
                j++;
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
