/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        var p1 = new ListNode(-1,head);
        var p2 = head;
        var res = p1;
        for(var i=0;i<n;i++)
            p2 = p2.next;
        while(p2!=null)
        {
            p2 = p2.next;
            p1 = p1.next;
        }
        p1.next = p1.next.next;
        return res.next;
    }
}
