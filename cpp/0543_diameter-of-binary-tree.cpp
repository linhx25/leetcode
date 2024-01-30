/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int depth(TreeNode* root, int & diagmeter){
        if(root==nullptr) return 0;
        int leftD = depth(root->left, diagmeter);
        int rightD = depth(root->right, diagmeter);
        diagmeter = max(diagmeter, leftD + rightD);
        return max(leftD, rightD) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diagmeter = 0;
        depth(root, diagmeter);
        return diagmeter;
    }
};
// @lc code=end

