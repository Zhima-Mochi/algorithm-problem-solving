import java.util.List;

/*
 * @lc app=leetcode id=725 lang=java
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    // public class ListNode {
    // int val;
    // ListNode next;

    // ListNode() {
    // }

    // ListNode(int val) {
    // this.val = val;
    // }

    // ListNode(int val, ListNode next) {
    // this.val = val;
    // this.next = next;
    // }
    // }

    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] res = new ListNode[k];
        int count = 0;
        ListNode cur = head;
        while (cur != null) {
            ++count;
            cur = cur.next;
        }
        int group_size = count / k;
        int rest = count % k;
        cur = head;
        int pos = 0;
        while (cur != null) {
            res[pos++] = cur;
            for (int i = 0; i < group_size - 1; ++i) {
                cur = cur.next;
            }
            if (group_size > 0 && rest > 0) {
                cur = cur.next;
                --rest;
            }
            ListNode next_cur = cur.next;
            cur.next = null;
            cur = next_cur;
        }
        return res;
    }
}
// @lc code=end
