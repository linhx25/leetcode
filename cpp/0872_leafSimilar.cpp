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
// dfs两棵树，cpp里面两个vector是有重载==运算符的！
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        traverse(root1,r1);
        traverse(root2,r2);
        return r1==r2;
    }
    void traverse(TreeNode* root,vector<int> &record)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr)
            record.push_back(root->val);
        traverse(root->left,record);
        traverse(root->right,record);
    }
};
