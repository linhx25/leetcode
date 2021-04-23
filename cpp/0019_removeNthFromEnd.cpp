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
// 用一个定长n的窗口，移动到最后即可。
// 注意细节：头指针，判断倒数第几个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = new ListNode();
        p1->next = head;
        auto p2 = head,res=p1;
        for(auto i=0;i<n;i++)
            p2 = p2->next;
        while(p2!=nullptr)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p1->next->next;
        return res->next;
    }
};
