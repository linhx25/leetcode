/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 先DFS，然后求再遍历求平均即可
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<long int>> record; // [(sum,count),...()]
        traverse(root,record,0);
        vector<double> res;
        for(auto item:record)
            res.push_back((double)(item[0])/item[1]);
        return res;
    }
    void traverse(TreeNode* root,vector<vector<long int>> &record,int depth)
    {
        if(root==nullptr)
            return;
        if(depth<record.size())
        {
            record[depth][0]+=root->val;
            record[depth][1]+=1;
        }
        else
            record.push_back({root->val,1});
        traverse(root->left,record,depth+1);
        traverse(root->right,record,depth+1);
    }
};
