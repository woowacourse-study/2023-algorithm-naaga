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
public class LinkedList_LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        ListNode current = head;
        if(current == null || current.next == null) { //if current node null or there's onyl one node.
            return false;
        }
        //slow = jump 1 node
        //fast = jump 2 node
        ListNode slow = current.next;
        ListNode fast = current.next.next;
        while(fast!=null && fast.next!=null) {
            if(slow == fast) {
                return true;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return false;
    }
}
