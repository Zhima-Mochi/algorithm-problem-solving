/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */
#include <cstdlib>
#include <ctime>
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        _head = head;
        srand(time(nullptr));
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        auto cur = _head;
        int res = cur->val;
        int count = 1;
        while (cur->next)
        {
            ++count;
            cur = cur->next;
            if ((rand() % count) == 0)
            {
                res = cur->val;
            }
        }
        return res;
    }

private:
    ListNode *_head;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

// class Solution
// {
// public:
//     /** @param head The linked list's head.
//         Note that the head is guaranteed to be not null, so it contains at least one node. */
//     Solution(ListNode *head)
//     {
//         _head = head;
//         len = 1;
//         while (head->next)
//         {
//             ++len;
//             head = head->next;
//         }
//         srand(time(nullptr));
//     }
//     /** Returns a random node's value. */
//     int getRandom()
//     {
//         int index = rand() % len;
//         auto cur = _head;
//         while (index--)
//         {
//             cur = cur->next;
//         }
//         return cur->val;
//     }

// private:
//     ListNode *_head;
//     int len;
// };