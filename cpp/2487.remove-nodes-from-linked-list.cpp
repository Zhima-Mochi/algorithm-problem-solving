/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <vector>
using namespace std;
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
// t:O(n), s:O(n)
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *dummy = new ListNode(100000, head);
        vector<ListNode *> stk;
        stk.push_back(dummy);
        auto cur = head;
        while (cur)
        {
            while (stk.back()->val < cur->val)
            {
                stk.pop_back();
            }
            stk.back()->next = cur;
            stk.push_back(cur);
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end
