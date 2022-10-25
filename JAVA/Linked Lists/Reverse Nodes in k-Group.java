// https://leetcode.com/problems/reverse-nodes-in-k-group/

 class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
		/**
		* The first rule is if k = 1 we don't need to swap anything. 
		* That is because the only way is to swap with itself that doesn't make any sense
		*/
        if (k == 1) return head;
		
		/**
		* That is my favourite technique to have the top handler of LinkedList. 
		* It prevents from accidentally losing or damaging the head node somewhere in our code
		*/
        ListNode root = new ListNode(-1);
        root.next = head;

		/**
		* That approach helps us to know beforehand how many groups are available for reversing. 
		* e.g if head = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 and k = 3 we will know that only 1 -> 2 -> 3 
		* and 4 -> 5 -> 6 are groups that need to be swapped and not to touch 7 -> 8
		*/
        int count = countNodes(head);
        int reverseCount = count / k;
        ListNode node = root;
        while (reverseCount > 0) {
            node = reverse(node, k);
            reverseCount--;
        }

        return root.next;
    }

	 
    public ListNode reverse(ListNode node, int k) {
        ListNode curr = node.next;
        ListNode tail = null;
        ListNode reversed = null;

        while (k > 0 && curr != null) {
            ListNode newNode = curr.next;
            curr.next = reversed;
            reversed = curr;
            curr = newNode;
            if (reversed.next == null) tail = reversed;

            k--;
        }

        tail.next = curr;
        node.next = reversed;

        return tail;
    }

    public int countNodes(ListNode node) {
        int count = 0;
        while (node != null) {
            count++;
            node = node.next;
        }

        return count;
    }
}
