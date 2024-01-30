/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==nullptr) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()){
            auto [node, levelIndex] = q.front();
            q.pop();
            if (levelIndex >= res.size())
                res.push_back({node->val});
            else
                res[levelIndex].push_back(node->val);
            if (node->left) q.emplace(node->left, levelIndex+1);
            if (node->right) q.emplace(node->right, levelIndex+1);
        }
        return res;        
    }
};
// @lc code=end

