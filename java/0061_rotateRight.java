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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null)
            return head;
        var p1 = new ListNode(-1,head);
        int n = 1;
        while(head.next!=null)
        {
            head = head.next;
            n++;
        }
        head.next = p1.next;
        k = n - k%n;
        n = 0;
        while(n<k)
        {
            p1 = p1.next;
            n++;
        }
        head = p1.next;
        p1.next = null;
        return head;
    }
}
