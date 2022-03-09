/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return;
        }
        auto slow = head, fast = head;
        while (fast->next && (fast = fast->next->next))
        {
            slow = slow->next;
        }
        auto cur = slow->next;

        while (cur->next)
        {
            auto target = slow->next;
            slow->next = cur->next;
            cur->next = cur->next->next;
            slow->next->next = target;
        }

        auto sub_head = slow->next;
        slow->next = nullptr;
        auto pre_head = head;
        while (sub_head)
        {
            auto next_pre_head = pre_head->next;
            pre_head->next = sub_head;
            sub_head = sub_head->next;
            pre_head->next->next = next_pre_head;
            pre_head = next_pre_head;
        }
    }
};
// @lc code=end
