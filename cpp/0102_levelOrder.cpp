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
// 用一个depth变量记录当前的深度
// 前序遍历二叉树时按照深度添加到结果数组里
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(0,root,res);
        return res;
    }
    void traverse(int depth, TreeNode* root, vector<vector<int>> &res)
    {
        if(root==nullptr)
            return;
        
        if(depth < res.size())
            res[depth].push_back(root->val);
        else
            res.push_back({root->val});
        traverse(depth+1,root->left,res);
        traverse(depth+1,root->right,res);
    }
};
