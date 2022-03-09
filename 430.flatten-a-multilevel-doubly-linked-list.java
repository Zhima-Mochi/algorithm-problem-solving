import java.util.Stack;

/*
 * @lc app=leetcode id=430 lang=java
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
// @lc code=start
/*
 * // Definition for a Node. class Node { public int val; public Node prev;
 * public Node next; public Node child; };
 */

class Solution {
    public Node flatten(Node head) {
        if (head == null) {
            return head;
        }
        var cur = head;
        Stack<Node> st = new Stack<Node>();
        while (true) {
            if (cur.child != null) {
                if (cur.next != null) {
                    st.push(cur.next);
                }
                cur.next = cur.child;
                cur.next.prev = cur;
                cur.child = null;
                cur = cur.next;
            } else if (cur.next != null) {
                cur = cur.next;

            } else if (!st.empty()) {
                cur.next = st.pop();
                cur.next.prev = cur;
                cur = cur.next;
            } else {
                break;
            }
        }
        return head;
    }
}
// @lc code=end
