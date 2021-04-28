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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null)
            return l2;
        if(l2==null)
            return l1;
        var res = new ListNode(-1,l1);
        var pre = res;
        while(l1!=null && l2!=null)
        {
            if(l1.val>l2.val)
            {
                pre.next = l2;
                l2 = l2.next;
            }
            else
            {
                pre.next = l1;
                l1 = l1.next;
            }
            pre = pre.next;
        }
        while(l1!=null)
        {
            pre.next = l1;
            l1 = l1.next;
            pre = pre.next;
        }
        while(l2!=null)
        {
            pre.next = l2;
            l2 = l2.next;
            pre = pre.next;
        }
        return res.next;
    }
}
