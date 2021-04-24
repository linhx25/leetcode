/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode middleNode(ListNode head) {
        if(head.next==null)
            return head;
        ListNode p1=head,p2=head;
        while(p2!=null && p2.next!=null)
        {
            p2 = p2.next.next;
            p1 = p1.next;
        }
        return p1;
    }
}
