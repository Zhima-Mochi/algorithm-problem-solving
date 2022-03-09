/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto init_head = new ListNode(0);
        init_head->next = head;
        auto cur = head;
        auto res = init_head;
        while (cur != nullptr)
        {
            auto next_cur = cur->next;
            if (next_cur && next_cur->val == cur->val)
            {
                auto val = cur->val;
                cur = next_cur->next;
                while (cur && cur->val == val)
                {
                    cur = cur->next;
                }
            }
            else
            {
                res->next = cur;
                res = cur;
                cur = next_cur;
            }
        }
        res->next = cur;
        return init_head->next;
    }
};
// @lc code=end
