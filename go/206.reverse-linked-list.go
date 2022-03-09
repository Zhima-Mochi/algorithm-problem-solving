/*
 * @lc app=leetcode id=206 lang=golang
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {

	if head == nil {
		return head
	}
	prev_node := head
	cur_node := head.Next
	prev_node.Next = nil
	for cur_node != nil {
		prev_node, cur_node, cur_node.Next = cur_node, cur_node.Next, prev_node
	}
	return prev_node
}

// @lc code=end

