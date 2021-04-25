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
// 1.BST自然想到中序遍历，但是此题考点不在中序遍历（找到待删除节点）
// 2.一个待删除节点，被更新的情况有3种：
// （1）base case：叶子节点，直接删除即可；
// （2）有右子树，则继承者在右子树中序遍历的最左（不一定是左子树）
// （3）无右子树，则继承者为父节点，此时应该找到前一节点，作为更新的对象
// 3.当找到更新对象时，递归地删除更新对象的节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return nullptr;
        // find the node to be deleted
        if(key<root->val)
            root->left = deleteNode(root->left,key);
        else if(key>root->val)
            root->right = deleteNode(root->right,key);
        else
        {
            if(root->right==nullptr && root->left==nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root->right!=nullptr)
            {
                root->val = sucessor(root);
                root->right = deleteNode(root->right,root->val);
            }
            else //must be (root->left!=nullptr)
            {
                root->val = predecessor(root);
                root->left = deleteNode(root->left,root->val);
            }  
        }
        return root; 
    }
    int sucessor(TreeNode* root)
    {
        root = root->right;
        while(root->left!=nullptr)
            root = root->left;
        return root->val; 
    }
    int predecessor(TreeNode* root)
    {
        root = root->left;
        while(root->right!=nullptr)
            root=root->right;
        return root->val;
    }
};
