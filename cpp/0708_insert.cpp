class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto node = new Node(insertVal);
        if(!head){
            node->next = node;
            return node;
        }
        auto prev = head, curr = head->next;

        while(curr != head){
            if (
                (prev->val <= insertVal && insertVal <= curr->val) ||
                (prev->val > curr->val && (insertVal >= prev->val || insertVal <= curr->val))
            )
                break;
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
        return head;
    }
};