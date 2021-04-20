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
// DFS: 无脑DFS。。奇数层reverse
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root,res,0);
        if(res.size()<2)
            return res;
        for(auto i=1;i<res.size();i+=2)
            reverse(res[i].begin(),res[i].end());
        return res;
    }

    void traverse(TreeNode* root,vector<vector<int>> &res,int depth)
    {
        if(root==nullptr)
            return;
        if(res.size()>depth)
            res[depth].push_back(root->val);
        else
            res.push_back({root->val});
        traverse(root->left,res,depth+1);
        traverse(root->right,res,depth+1);
    }
};
