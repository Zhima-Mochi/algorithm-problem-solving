/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
struct
    ListNode;
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *preDel = head;
        ListNode *cur = head;
        for (int i = n; i != 0; i--)
        {
            cur = cur->next;
        }
        //if cur is nullptr, delete the first Node;
        if (cur == nullptr)
        {
            auto res = head->next;
            delete (head);
            return res;
        }
        else
        {
            cur = cur->next;
        }

        while (cur != nullptr)
        {
            cur = cur->next;
            preDel = preDel->next;
        }
        auto delNode = preDel->next;

        preDel->next = delNode->next;
        //delete (delNode);
        return head;
    }
};
// @lc code=end
