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
// DFS，每一层遍历一个节点就更新一次宽度，最后在层-宽度数组里取最大值
// ....必须用unsigned long long不然会溢出。。
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<long> record; // (depth-first_position) 
        unsigned long long res=0;
        traverse(root,record,res,0,0);
        return (int)res;
    }
    void traverse(TreeNode* root, vector<long> &record, unsigned long long &res, int depth, unsigned long long position)
    {
        if(root==nullptr)
            return;
        // record the first element in this layer
        if(record.size()<depth+1)
            record.push_back(position);
        
        // update max depth with position
        res = max(res,position-record[depth]+1);
        traverse(root->left,record,res,depth+1,position*2);
        traverse(root->right,record,res,depth+1,position*2+1);
    }
};
