/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Random Pick with Weight
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root==nullptr) return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;

        q.emplace(root, 0);
        while(!q.empty()){
            auto & [node, index] = q.front();
            q.pop();
            m[index].push_back(node->val);
            // if (m.count(index))
            //     m[index].push_back(node->val);
            // else
            //     m[index] = {node->val};
            if(node->left) q.emplace(node->left, index-1);
            if(node->right) q.emplace(node->right, index+1);
        }
        
        vector<vector<int>> res;
        for (auto &[k, v]: m)
            res.push_back(v);

        return res;
    }
};

// @lc code=end

