/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        auto slow = head, fast = head;
        while ((fast = fast->next) && (fast = fast->next))
        {
            slow = slow->next;
            if (slow == fast)
            {
                break;
            }
        }
        if (fast == nullptr)
        {
            return nullptr;
        }
        auto cur = head;
        while (cur != slow)
        {
            slow = slow->next;
            cur = cur->next;
        }
        return cur;
    }
};
// @lc code=end
