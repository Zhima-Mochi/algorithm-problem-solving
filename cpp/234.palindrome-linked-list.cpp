/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */
#include <stack>
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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return true;
        }
        auto fast = head, slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast != nullptr)
        {
            slow = slow->next;
        }
        if (slow == nullptr)
        {
            return head->val == head->next->val;
        }
        auto cur = slow->next;
        auto prev = slow;
        prev->next = nullptr;
        while (cur != nullptr)
        {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur = head;
        while (prev)
        {
            if (prev->val != cur->val)
            {
                return false;
            }
            prev = prev->next;
            cur = cur->next;
        }
        return true;
    }
};
// @lc code=end
