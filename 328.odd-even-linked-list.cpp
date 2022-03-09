/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }
        auto cur_1 = head;
        auto cur_2 = head->next;
        auto second_head = cur_2;
        while (cur_2)
        {
            cur_1->next = cur_2->next;
            if (cur_1->next)
            {
                cur_1 = cur_1->next;
                cur_2 = cur_2->next = cur_1->next;
            }
            else
            {
                break;
            }
        }
        cur_1->next = second_head;
        return head;
    }
};
// @lc code=end
