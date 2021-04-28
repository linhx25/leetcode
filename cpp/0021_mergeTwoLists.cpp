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
// 没啥特别的，直接对比，然后修改原链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode* res = new ListNode(-1,l1);
        ListNode* pre = res;
        while(l1!=nullptr && l2 !=nullptr)
        {
            if(l1->val>l2->val)
            {
                pre->next = l2;
                l2 = l2->next;
            }
            else
            {
                pre->next = l1;
                l1 = l1->next;
            }
            
            pre = pre->next;
        }
        while(l1!=nullptr)
        {
            pre->next = l1;
            l1 = l1->next;
            pre = pre->next;
        }
        while(l2!=nullptr)
        {
            pre->next = l2;
            l2 = l2->next;
            pre = pre->next;
        }
        return res->next;
    }
};
