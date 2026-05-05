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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode res = null;
        ListNode node = res;
        ListNode next;

        int n = lists.length;
        int temp,x;
        while(true){
            temp = 1001;
            x = -1;
            for(int i=0;i<n;i++){
                if(lists[i]!= null){
                    if(temp > lists[i].val){
                        temp = lists[i].val;
                        x = i;
                    }
                }    
            }

            if(x==-1)
                return res;

            System.out.println(temp);

            
            if(res == null){
                res = lists[x];
                node = lists[x]; 
            }else {
                node.next = lists[x];
                node = node.next;
            }

            next = lists[x].next;
            lists[x] = next;
            node.next = null;
              
        }

    
    }
}
