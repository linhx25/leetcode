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
// 用栈或者数组，双指针shrink检验回文
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head!=nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        auto p1=arr.begin(),p2=arr.end()-1;
        while(p1<=p2)
        {
            if(*p1!=*p2)
                return false;
            p1++;p2--;
        }
        return true;
    }
};
