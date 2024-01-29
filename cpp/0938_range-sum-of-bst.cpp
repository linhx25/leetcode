/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int sum=0;

    void inorder(TreeNode* root, int low, int high) {
        if (root){
            inorder(root->left, low, high);
            if (root-> val >= low && root->val <= high)
                sum += root->val;
            inorder(root->right, low, high);
        }
        else return;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {

        if(root != nullptr)
            inorder(root, low, high);
        return sum;
    }
};
// @lc code=end

