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

// DFS 比较每个叶子节点的深度，取最小
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int res = 10000000;
        traverse(root,0,res);
        return res;
    }
    void traverse(TreeNode* root,int depth,int& res)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr)
            res = min(res,depth+1);
        traverse(root->left,depth+1,res);
        traverse(root->right,depth+1,res);
    }
};
