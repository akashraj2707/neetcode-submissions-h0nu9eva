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

// 1 2 3 4 5 6
// 2 1 4 3
class Solution {
    

    public void reverse(ListNode start, ListNode end) {
    ListNode prev = end.next; // Connect the new tail to the rest of the list
    ListNode temp = start;
    ListNode stop = end.next; // Define exactly where to stop

    while (temp != stop) {
        ListNode next = temp.next;
        temp.next = prev;
        prev = temp;
        temp = next;
    }
    // Note: After this, 'prev' is the new head of this segment.
    // If you need to update the node before 'start', you must do it outside this method.
}
    public ListNode reverseKGroup(ListNode head, int k) {
        
        ListNode res= null;

        ListNode temp=head,start=head,end=null,prevEnd = null,next;

        int ctr=0;
        while(temp!=null){
            ctr ++;
            next = temp.next;

            if(ctr == k){
                end = temp;
                reverse(start,end);
                start.next = next;

                if(res == null){
                    res = end;
                }else {
                    prevEnd.next = end;
                }
                prevEnd = start;
                ctr=0;
                start = next;
                
            }

            temp = next;
        }

        return (res == null) ? head : res;
    }
}
