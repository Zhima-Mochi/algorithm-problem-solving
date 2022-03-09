/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        auto cur = head;
        auto sub_greater_head = new ListNode();
        auto sub_lower_head = new ListNode();
        auto sub_greater_head_cur=sub_greater_head;
        auto sub_lower_head_cur =sub_lower_head;
        while (cur != nullptr)
        {
            if (cur->val >= x)
            {
                sub_greater_head_cur->next = cur;
                sub_greater_head_cur=cur;
            }
            else
            {
                sub_lower_head_cur->next=cur;
                sub_lower_head_cur=cur;
            }
            cur = cur->next;
        }
        sub_greater_head_cur->next=nullptr;
        sub_lower_head_cur->next=sub_greater_head->next;
        return sub_lower_head->next;
    }
};
// @lc code=end
