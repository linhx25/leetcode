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
// 1.不要什么都无脑前序遍历，二叉搜索树（BST）的问题天然就是中序遍历；
// 2.所有已经遍历的节点必然比当前节点小。
// 3.用一个全局变量来记录之前一个节点的值
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long pre = LONG_MIN;
        return traverse(root, pre);
    }
    bool traverse(TreeNode* root, long long &pre)
    {
        if(root==nullptr)
            return true;
        
        if(!traverse(root->left,pre))
            return false;
        if(root->val<=pre)
            return false;
        pre = root->val;
        return traverse(root->right,pre);
    }
};
