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
class Solution
{
public
    ListNode reverseList(ListNode head)
    {
        ListNode start = head;
        ListNode prev = null;
        while (start != null)
        {
            ListNode nex = start.next;
            start.next = prev;
            prev = start;
            start = nex;
        }
        return prev;
    }
}