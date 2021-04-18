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
    // 非递归：栈
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root!=nullptr || !stk.empty())
        {
            // 访问左节点直到空
            while(root!=nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            // 左子树已经遍历完，此时栈顶元素即为应该出栈被记录的元素
            root = stk.top();
            res.push_back(root->val);
            // 出栈，此时栈顶元素为上一个元素的根节点（左根右，左已经记录）
            stk.pop();
            // 访问右节点
            root = root->right;
        }
        return res;
    }
};
// 递归
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traverse(res,root);
//         return res;
//     }
//     void traverse(vector<int> &res,TreeNode* root)
//     {
//         if(root==nullptr)
//             return;
//         traverse(res,root->left);
//         res.push_back(root->val);
//         traverse(res,root->right);
//     }
// };
