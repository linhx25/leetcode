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

// 和0113类似，但是这里不要求路径从根节点开始
// 1.用一个数组arr记录已经遍历的节点，用depth记录深度以及控制清空数组的已经遍历的元素；
// 2.每次倒着检查arr数组是否有满足条件的路径，有则记录
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        vector<int> arr;
        traverse(root,targetSum,arr,res,1);
        return res;
    }
    void traverse(TreeNode* root,int targetSum, vector<int> &arr, int &res,int depth)
    {
        if(root==nullptr)
            return;
        while(arr.size()>=depth)
            arr.erase(arr.end()-1);
        arr.push_back(root->val);
        int sum=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            sum += arr[i];
            if(sum==targetSum)
                res++;
        }
        traverse(root->left,targetSum,arr,res,depth+1);
        traverse(root->right,targetSum,arr,res,depth+1);
    }
};
