/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
#include <unordered_set>
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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> collection;
        for (auto n : nums)
        {
            collection.insert(n);
        }
        auto cur = head;
        int count = 0;
        int res = 0;
        while (cur != nullptr)
        {
            if (collection.count(cur->val))
            {
                ++count;
            }
            else if (count > 0)
            {
                ++res;
                count = 0;
            }
            cur = cur->next;
        }
        if (count)
        {
            ++res;
        }
        return res;
    }
};
// @lc code=end
