/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include <vector>
#include <algorithm>
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
    static bool compf(ListNode *a, ListNode *b)
    {
        return (*a).val > (*b).val;
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode();
        auto cur = head;
        vector<ListNode *> list_cur;
        for (auto c : lists)
        {
            if (c != nullptr)
            {
                list_cur.push_back(c);
            }
        }

        make_heap(list_cur.begin(), list_cur.end(), compf);
        while (list_cur.size())
        {
            pop_heap(list_cur.begin(), list_cur.end(), compf);
            auto min = list_cur.back();
            list_cur.pop_back();
            cur->next = new ListNode(min->val);
            cur = cur->next;
            auto next=min->next;
            if (next != nullptr)
            {
                list_cur.push_back(next);
                push_heap(list_cur.begin(), list_cur.end(), compf);
            }
            
            //cout<<list_cur.size();
        }
        cur = head->next;
        delete (head);

        return cur;
    }
};
// @lc code=end
