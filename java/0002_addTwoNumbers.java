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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        var res = new ListNode(-1,l1);
        var pre_l1 = new ListNode(-1,l1);
        int place = 0;
        while(l1!=null && l2!=null)
        {
            int tmp = place + l1.val + l2.val;
            l1.val = tmp%10;
            place = tmp/10;
            l1 = l1.next;pre_l1 = pre_l1.next;
            l2 = l2.next;
        }
        while(l1!=null)
        {
            int tmp = place + l1.val;
            l1.val = tmp%10;
            place = tmp/10;
            l1 = l1.next;pre_l1 = pre_l1.next;   
        }
        while(l2!=null)
        {
            if(l1==null)
                pre_l1.next = l2;
            int tmp = place + l2.val;
            l2.val = tmp%10;
            place = tmp/10;
            l2 = l2.next;pre_l1 = pre_l1.next;   
        }
        if(l1==null && place!=0)
            pre_l1.next = new ListNode(place);
        if(l1!=null && place!=0)
            pre_l1.next = new ListNode(place);
        return res.next;
    }
}
