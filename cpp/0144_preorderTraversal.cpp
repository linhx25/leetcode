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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // stack 的作用，每个元素都是下一个元素的根节点
        stack<TreeNode*> stk;
        while(!stk.empty() || root!=nullptr)
        {
            while(root!=nullptr)
            {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};

// // 前序遍历：根左右
// class Solution {
// public:

//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traverse(res,root);
//         return res;
//     }

//     void traverse(vector<int> &res, TreeNode *root)
//     {
//         if(root == nullptr)
//             return;
        
//         res.push_back(root->val);
//         traverse(res,root->left);
//         traverse(res,root->right);
//     }
// };
