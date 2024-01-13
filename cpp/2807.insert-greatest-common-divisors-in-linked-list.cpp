/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <numeric>
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
// t:O(n), s:O(1)
class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        auto cur = head;
        while (cur->next)
        {
            ListNode *node = new ListNode(gcd(cur->val, cur->next->val), cur->next);
            cur->next = node;
            cur = node->next;
        }
        return head;
    }
};
// @lc code=end
