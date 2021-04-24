/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// BF: 先搜索一遍得到长度，再找到对应中位数
// 改进：由于不知道长度，所以必须搜索一遍，但可以利用快慢指针，快指针比慢指针多走一倍路程

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next ==NULL)
            return head;
        auto p1=head,p2=head;
        while(p2!=NULL && p2->next!=NULL)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }
};
