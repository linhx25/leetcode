/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
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
class Solution {
public:
    void traversal(TreeNode* root, int level, vector<int> &res){
        if (root==nullptr) return;
        if (res.size() == level) res.push_back(root->val);
        if (root->right) traversal(root->right, level+1, res);
        if (root->left) traversal(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root==nullptr) return {};
        vector<int> res;
        traversal(root, 0, res);
        return res;
    }
};
// @lc code=end

