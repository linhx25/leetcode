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
// 递归：每次递归一层都更新该层的maxdepth = 1+max(左，右) 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return traverse(root);
    }
    int traverse(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return 1+max(traverse(root->left),traverse(root->right));
    }
};
