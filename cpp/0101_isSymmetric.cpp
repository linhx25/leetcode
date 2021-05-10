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
// 镜像同时遍历对称的左、右子树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return traverse(root,root);
    }
    bool traverse(TreeNode* r1,TreeNode* r2)
    {
        if(r1==nullptr && r2!=nullptr || r1!=nullptr && r2==nullptr)
            return false;
        else if (r1==nullptr && r2==nullptr)
            return true;
        return (r1->val==r2->val) && traverse(r1->left,r2->right) && traverse(r1->right,r2->left);
    }
};
