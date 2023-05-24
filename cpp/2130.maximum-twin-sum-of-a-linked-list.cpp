/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        auto slow = head, fast = head;
        vector<int> points;
        while (fast != nullptr && fast->next != nullptr)
        {
            points.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int res = 1;
        while (slow != nullptr)
        {
            res = max(res, points.back() + slow->val);
            points.pop_back();
            slow = slow->next;
        }
        return res;
    }
};
// @lc code=end
