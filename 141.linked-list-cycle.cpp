/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto cur = head;
        auto quick_cur = head;
        if(cur==nullptr){
            return false;
        }
        while (quick_cur->next != nullptr && (quick_cur = quick_cur->next->next) != nullptr)
        {
            head = head->next;
            if (head == quick_cur)
                return true;
        }
        return false;
        // auto cur = head;
        // while (cur != nullptr)
        // {
        //     auto next = cur->next;
        //     if (next == head)
        //     {
        //         return true;
        //     }
        //     else
        //     {
        //         cur->next = head;
        //         cur = next;
        //     }
        // }
        // return false;
    }
};
// @lc code=end
