/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null)
            return null;
        ListNode p1=head,p2=head,p3=head;
        while(p2!=null && p2.next!=null)
        {
            p2 = p2.next.next;
            p1 = p1.next;
            if(p2==p1)
            {
                while(p3!=p2)
                {
                    p3 = p3.next;
                    p2 = p2.next;
                }
                return p3;
            }
        }
        return null;
    }
}
