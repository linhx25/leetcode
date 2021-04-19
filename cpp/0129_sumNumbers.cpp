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
// 递归：每次修改根节点的值为父节点的值*10+根节点的值，最后对叶子节点求和
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        TreeNode* parent = nullptr;
        traverse(root,parent,res);
        return res;
    }
    void traverse(TreeNode* root, TreeNode* parent,int &res)
    {
        if(root==nullptr)
            return;
        if(parent!=nullptr)
            root->val += parent->val * 10;
        if(root->right==nullptr && root->left==nullptr)
            res += root->val;
        traverse(root->left, root, res);
        traverse(root->right, root, res);
    }
};
