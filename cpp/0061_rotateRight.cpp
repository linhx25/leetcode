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
// 数组版本 - [0189_rotate]
// 1.双指针，一个指针遍历完，接上循环链表，同时计数得到长度n；
// 2.另一个指针从开头移动n-k%n，断开链表
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
            return head;
        ListNode* p1 = new ListNode(-1,head);
        int n=1;
        while(head->next!=nullptr)
        {
            head = head->next;
            n++;
        }
        head->next = p1->next;
        k = n-k%n;
        n=0;
        while(n<k)
        {
            p1 = p1->next;
            n++;
        }
        head = p1->next;
        p1->next = nullptr;
        return head;
    }
};
