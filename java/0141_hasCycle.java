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
    public boolean hasCycle(ListNode head) {
        ListNode p1=head,p2=head;
        while(p2!=null && p2.next!=null)
        {
            if(p2.next==p1)
                return true;
            p2 = p2.next.next;
            p1 = p1.next;
        }
        return false;    
    }
}
