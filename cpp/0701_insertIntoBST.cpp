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
// 搜索待插入的节点：
// 1. 如果大于root，有右子树，则往右插入；如果无右子树，新建节点；
// 2. 如果小于root，有左子树，往左插入；如果无左子树，新建节点
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
            return new TreeNode(val);
        if(root->val>val && root->left!=nullptr)
            root->left = insertIntoBST(root->left,val);
        else if(root->val>val && root->left==nullptr)
            root->left = new TreeNode(val);
        else if(root->val<val && root->right!=nullptr)
            root->right = insertIntoBST(root->right,val);
        else // must be(root->val<val && root->right==nullptr)
            root->right = new TreeNode(val);
        return root;
    }
};
