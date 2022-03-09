/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */
#include <iostream>
using namespace std;
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
        {
            return head;
        }
        auto init_head = new ListNode(0, head);
        auto cur = init_head;
        while (cur->next)
        {
            auto count = 0;
            auto bound_cur = cur->next;
            while (bound_cur && count != k)
            {
                bound_cur = bound_cur->next;
                ++count;
            }
            if (count != k)
            {
                break;
            }
            auto tail_cur = cur->next;
            while (tail_cur->next != bound_cur)
            {
                auto next_point_cur=cur->next;
                cur->next=tail_cur->next;
                tail_cur->next=tail_cur->next->next;
                cur->next->next=next_point_cur;
            }
            cur=tail_cur;
        }
        return init_head->next;
    }
};
// @lc code=end
