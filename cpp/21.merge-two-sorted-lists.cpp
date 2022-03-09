/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
struct ListNode;
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        auto res = new ListNode(), h_res = res;
        auto cur1 = l1, cur2 = l2;
        for (; cur1 != nullptr && cur2 != nullptr;)
        {
            if (cur1->val <= cur2->val)
            {
                res->next = new ListNode(cur1->val);
                res = res->next;
                cur1 = cur1->next;
            }
            else
            {
                res->next = new ListNode(cur2->val);
                res = res->next;
                cur2 = cur2->next;
            }
        }
        while (cur1 != nullptr)
        {
            res->next = new ListNode(cur1->val);
            res = res->next;
            cur1 = cur1->next;
        }

        while (cur2 != nullptr)
        {
            res->next = new ListNode(cur2->val);
            res = res->next;
            cur2 = cur2->next;
        }
        res = h_res->next;
        delete (h_res);
        return res;
    }
};
// @lc code=end
