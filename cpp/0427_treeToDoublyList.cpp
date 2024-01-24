class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* prev = nullptr;
    Node* head = nullptr;

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        dfs(root);
        prev->left = head; // after the dfs the prev is the rightmost
        head->right = prev;

        return head;
    }

    void dfs(Node* root) {
        if (root == nullptr) // !root means root==nullptr
            return;
        
        dfs(root->left);
        if (prev == nullptr)
            head = root;
        else{
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        dfs(root->right);
    }
};