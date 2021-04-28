/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        var p1 = new ListNode(headA.val);
        var p2 = new ListNode(headB.val);
        p1.next = headA.next;p2.next = headB.next;
        while(p1!=null && p2!=null)
        {
            p1 = p1.next;
            p2 = p2.next;
        }
        while(p1!=null)
        {
            p1 = p1.next;
            headA = headA.next;
        }
        while(p2!=null)
        {
            p2 = p2.next;
            headB = headB.next;
        }
        while(headB!=null && headA!=null && headA!=headB)
        {
            headA = headA.next;
            headB = headB.next;
        }
        return headB;
    }
}
