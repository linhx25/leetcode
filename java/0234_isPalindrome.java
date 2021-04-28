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
    public boolean isPalindrome(ListNode head) {
        List<Integer> arr = new ArrayList<>();
        while(head!=null)
        {
            arr.add(head.val);
            head = head.next;
        }
        int p1=0,p2=(int)arr.size()-1;
        while(p1<=p2)
        {
            if(arr.get(p1)!=arr.get(p2))
                return false;
            p1++;p2--;
        }
        return true;
    }
}
