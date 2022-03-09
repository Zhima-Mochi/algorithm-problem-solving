/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
// t:O(N), s:O(N)
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur = prev;
        vector<int> res;
        vector<int> st;
        while (cur)
        {
            while (!st.empty() && st.back() <= cur->val)
            {
                st.pop_back();
            }
            if (st.empty())
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(st.back());
            }
            st.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
