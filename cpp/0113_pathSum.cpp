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
// 1. DFS,每层累加number,用一个数组来记录路径，用depth记录深度以及控制是否erase数组最后一个元素（如果数组的长度大于深度则erase）
// 2. 如果number==target && 是叶子节点，记录
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> arr;
        traverse(root,0,targetSum,res,arr,1);
        return res;
    }
    void traverse(TreeNode* root,int sum, int targetSum, vector<vector<int>> &res, vector<int> &arr, int depth)
    {
        if(root==nullptr)
            return;  
        
        while(arr.size()>=depth)
            arr.erase(arr.end()-1);
        arr.push_back(root->val);
        
        if(root->right==nullptr && root->left==nullptr && sum+root->val == targetSum)
            res.push_back(arr);
        traverse(root->left,sum+root->val,targetSum,res,arr,depth+1);
        traverse(root->right,sum+root->val,targetSum,res,arr,depth+1);
    }
};
