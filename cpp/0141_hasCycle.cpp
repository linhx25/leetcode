/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 环链表，快慢指针
// 快指针如果遇到null，则返回false
// 如果快指针遇到慢指针，返回true
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto p1=head,p2=head;
        if(p1==NULL)
            return false;
        else
            p2=head->next;
        while(p2!=NULL && p2->next!=NULL)
        {
            if(p2==p1)
                return true;
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return false;
    }
};
