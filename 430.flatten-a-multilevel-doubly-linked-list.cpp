/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        auto cur = head;
        stack<Node *> st;
        while (true)
        {
            if (cur->child)
            {
                if (cur->next)
                {
                    st.push(cur->next);
                }
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
                cur = cur->next;
            }
            else if (cur->next)
            {
                cur = cur->next;
            }
            else if (!st.empty())
            {
                cur->next = st.top();
                cur->next->prev = cur;
                st.pop();
                cur = cur->next;
            }
            else
            {
                break;
            }
        }
        return head;
    }
};
// @lc code=end
