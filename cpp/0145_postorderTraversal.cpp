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
// 非递归：栈
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* visted = nullptr;
        while(!stk.empty() || root!=nullptr)
        {
            while(root!=nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            // 左子树遍历完，遍历右子树
            // 右子树如果已经遍历过，才记录根，否则继续遍历右
            if(root->right==nullptr || root->right==visted)
            {
                res.push_back(root->val);
                visted = root; // 标记该节点已经遍历过
                root = nullptr; // 记录已经遍历，从而跳到上一层root
            }
            else
            {
                stk.push(root);
                root = root->right;
            }
            

        }
        return res;
    }
};

//  后序遍历：左右根
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traverse(res,root);
//         return res;
//     }
//     void traverse(vector<int>& res, TreeNode* root)
//     {
//         if(root==nullptr)
//             return;        
//         traverse(res,root->left);
//         traverse(res,root->right);
//         res.push_back(root->val);
//     }
// };
