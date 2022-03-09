/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        auto init_head = new ListNode();
        init_head->next = head;
        ListNode *pre_sub = init_head;
        while (--left != 0)
        {
            --right;
            pre_sub = pre_sub->next;
        }
        auto prev_cur = pre_sub->next;
        auto sub_tail = prev_cur;
        while (--right != 0)
        {
            pre_sub->next = sub_tail->next;
            sub_tail->next = sub_tail->next->next;
            pre_sub->next->next = prev_cur;
            prev_cur = pre_sub->next;
        }
        return init_head->next;
    }
};
// @lc code=end
