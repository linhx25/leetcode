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
// DFS: global一个diff变量记录左右树高度差；前序遍历求树的最大深度时更新高度差
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int diff = 0;
        traverse(root,0,diff);
        return diff>1?false:true;
    }
    int traverse(TreeNode* root,int depth, int &diff)
    {
        if(root==nullptr)
            return 0;
        int left = traverse(root->left,++depth,diff);
        int right = traverse(root->right,++depth,diff);
        diff = max(diff,abs(left-right));
        return 1 + max(left,right);
    }
};
