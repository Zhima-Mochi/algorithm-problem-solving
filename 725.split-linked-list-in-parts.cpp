/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */
#include <vector>
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> res = {head};
        int count = 0;
        ListNode *cur = head;
        while (cur)
        {
            ++count;
            cur = cur->next;
        }
        int group_size = count / k;
        int rest = count % k;
        cur = head;
        count = 0;
        while (cur)
        {
            ++count;
            if (group_size == 0)
            {
                auto next_cur = cur->next;
                cur->next = nullptr;
                cur = next_cur;
                res.push_back(cur);
            }
            else if (count % group_size == 0)
            {
                if (rest)
                {
                    cur = cur->next;
                    --rest;
                }
                auto next_cur = cur->next;
                cur->next = nullptr;
                cur = next_cur;
                res.push_back(cur);
            }
            else
            {
                cur = cur->next;
            }
        }
        res.resize(k);
        return res;
    }
};
// @lc code=end
