/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 3个指针标记位置，可以画图
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr)
            return head;
        ListNode* p1=head,*p2=head->next,*p3=head->next->next;
        p1->next = nullptr;
        while(p3!=nullptr)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};
