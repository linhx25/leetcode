/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1.两个指针同时移动，当一个指针到达终点时，另一个链表的头指针开始移动直到该链表的右指针到达终点；
// 2.此时两个链表的头指针已经对齐了，遍历知道相交就可以（如果不相交则是null）
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1!=NULL && p2!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1!=NULL)
        {
            p1 = p1->next;
            headA = headA->next;
        }
        while(p2!=NULL)
        {
            p2 = p2->next;
            headB = headB->next;
        }
        while(headA!=NULL && headB!=NULL && headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
