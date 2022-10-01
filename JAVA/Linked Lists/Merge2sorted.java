class Solution {
    public ListNode mergeTwoLinkedLists(ListNode head1, ListNode head2) {
        if(head1==null && head2==null) //if both lists are empty
            return null;
        else if(head1==null && head2!=null) //if 1st list is empty
            return head2;
        else if(head2==null && head1!=null) //if 2nd list is empty
            return head1;
        if(head1.val<=head2.val) //if value of node in 1st list is smaller than or equal to value of node in 2nd list
            head1.next = mergeTwoLinkedLists(head1.next,head2);
        else //if value of node in 1st list is greater than value of node in 2nd list
        {
            ListNode temp = head2;
            head2 = head2.next;
            temp.next = head1;
            head1 = temp;
            head1.next = mergeTwoLinkedLists(head1.next,head2);
        }
        return head1;
        
    }
}