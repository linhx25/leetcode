/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int preOrder(TreeNode* root, int currSum){
        if(root==nullptr) return 0;
        currSum = currSum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr)
            return currSum;
        return preOrder(root->left, currSum) + preOrder(root->right, currSum);
    }

    int sumNumbers(TreeNode* root) {
        return preOrder(root, 0);
    }
};
// @lc code=end

