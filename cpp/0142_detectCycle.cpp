/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 注意到p2的路程等于p1的两倍，因此可以画图推出当p1p2相遇时，
// 起点到入口的路程和p2到环入口的路程相等。
// 因此可以在p1p2相遇时，用一个指针p3从头开始遍历,p2常速遍历，p3与p2相遇时,p2的位置即入口(注意细节，可以用一般的case推理一下)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto p1=head,p2=head;
        if(p1==NULL)
            return NULL;
        while(p2!=NULL && p2->next!=NULL)
        {
            p2 = p2->next->next;
            p1 = p1->next;
            if(p2==p1)
            {
                p1=head;
                while(p1!=p2)
                {
                    p2 = p2->next;
                    p1 = p1->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};
