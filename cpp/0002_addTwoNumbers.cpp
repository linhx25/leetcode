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
// 1.没什么特殊处理，两个链表是倒序对齐的，因此直接相加就行；
// 2.用一个变量来存储进位的数值
// 3.直接修改原先的链表，节省一些空间
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1,l1);
        ListNode* pre_l1 = new ListNode(-1,l1);
        int place=0;
        while(l1!=nullptr && l2!=nullptr)
        {
            int tmp = place + l1->val + l2->val;
            l1->val = tmp%10;
            place = tmp/10;
            l1=l1->next;pre_l1 = pre_l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr)//case1:l2==nullptr
        {
            int tmp = place + l1->val;
            l1->val = tmp%10;
            place = tmp/10;
            l1 = l1->next;pre_l1 = pre_l1->next;
        }
        while(l2!=nullptr)//case2:11==nullptr
        {
            if(l1==nullptr)
                pre_l1->next = l2;

            int tmp = place + l2->val;
            l2->val = tmp%10;
            place = tmp/10;
            l2 = l2->next;pre_l1 = pre_l1->next;
        }
        if(l1==nullptr && place!=0)//must be case1
            pre_l1->next = new ListNode(place);
        if(l1!=nullptr && place!=0)//must be case2
            pre_l1->next = new ListNode(place);
        return res->next;
    }
};
