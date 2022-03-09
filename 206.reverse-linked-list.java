/*
 * @lc app=leetcode id=206 lang=java
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    // public class ListNode {
    //     int val;
    //     ListNode next;

    //     ListNode() {
    //     }

    //     ListNode(int val) {
    //         this.val = val;
    //     }

    //     ListNode(int val, ListNode next) {
    //         this.val = val;
    //         this.next = next;
    //     }
    // }
    public ListNode reverseList(ListNode head) {
        ListNode prev_node = null;
        var cur = head;
        while (cur != null) {
            var next_cur = cur.next;
            cur.next = prev_node;
            prev_node = cur;
            cur = next_cur;
        }
        return prev_node;
    }
}
// @lc code=end
