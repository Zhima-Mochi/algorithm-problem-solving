/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        auto init_head = new ListNode(0, head);
        auto tail = head;
        while (tail->next)
        {
            
            if (tail->next->val >= tail->val)
            {
                tail = tail->next;
            }
            else
            {
                auto tail_next_cur = tail->next->next;
                insertion(init_head, tail->next);
                tail->next = tail_next_cur;
            }
        }
        return init_head->next;
    }
    void insertion(ListNode *pre_head, ListNode *new_node)
    {
        auto cur = pre_head;
        while (cur)
        {
            if (new_node->val < cur->next->val)
            {
                new_node->next = cur->next;
                cur->next = new_node;
                break;
            }
            else
            {
                cur = cur->next;
            }
        }
    }
};
// @lc code=end
