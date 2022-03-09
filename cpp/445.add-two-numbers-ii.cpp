/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<ListNode *> st_1, st_2;
        while (l1)
        {
            st_1.push_back(l1);
            l1 = l1->next;
        }
        while (l2)
        {
            st_2.push_back(l2);
            l2 = l2->next;
        }
        if (st_1.size() < st_2.size())
        {
            swap(st_1, st_2);
        }
        bool carry = false;
        auto head = st_1.front();
        while (!st_2.empty())
        {
            st_1.back()->val += st_2.back()->val + (carry ? 1 : 0);
            if (st_1.back()->val >= 10)
            {
                carry = true;
                st_1.back()->val %= 10;
            }
            else
            {
                carry = false;
            }
            st_1.pop_back();
            st_2.pop_back();
        }
        while (carry && !st_1.empty())
        {
            st_1.back()->val += carry ? 1 : 0;
            if (st_1.back()->val >= 10)
            {
                carry = true;
                st_1.back()->val %= 10;
            }
            else
            {
                carry = false;
            }
            st_1.pop_back();
        }
        if (st_1.empty())
        {
            if (carry)
            {
                return new ListNode(1, head);
            }
            else
            {
                return head;
            }
        }
        else
        {
            return head;
        }
    }
};
// @lc code=end
