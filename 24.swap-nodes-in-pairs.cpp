/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *init_head = new ListNode(0, head);
        auto prev_end = init_head;
        auto current_node = init_head->next;
        stack<ListNode *> node_stack;
        //I use stack for more extensible
        while (current_node != nullptr)
        {

            if (node_stack.size() != 1)
            {
                node_stack.push(current_node);
                //Update current node
                current_node = current_node->next;
            }
            else
            {
                auto tail_node = node_stack.top();
                node_stack.pop();
                tail_node->next = current_node->next;
                prev_end->next = current_node;
                //Notice to update prev_end;
                prev_end=current_node->next = tail_node;
                
                //Update current node
                current_node = tail_node->next;
            }
        }
        return init_head->next;
    }
};
// @lc code=end
