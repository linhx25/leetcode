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

// BFS: 自顶向下使用队列（fifo），自底向上用数组（filo），用一个数组记录每一层宽度
// DFS: 用forward_list或者deque都可以在顶端插入，但是返回值指定了vector所以不方便，还是老实用vector最后反转吧
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root,0,res);
        reverse(res.begin(),res.end());
        return res;
    }
    void traverse(TreeNode* root,int depth,vector<vector<int>> &res)
    {
        if(root==nullptr)
            return;
        if(res.size()<=depth)
            res.push_back({root->val});
        else
            res[depth].push_back(root->val);
        traverse(root->left,depth+1,res);
        traverse(root->right,depth+1,res);
    }
};
