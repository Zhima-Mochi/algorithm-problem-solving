/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
#include <unordered_map>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        auto cur = head;
        while (cur)
        {
            auto next_cur = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next_cur;
            cur = next_cur;
        }

        cur = head;
        while (cur)
        {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        auto root = head->next;
        cur = head;
        while (cur)
        {
            auto next_cur = cur->next->next;
            if (next_cur)
            {
                cur->next->next = next_cur->next;
            }
            cur->next = next_cur;
            cur = next_cur;
        }
        return root;
        // unordered_map<Node *, Node *> umap;
        // auto cur = head;
        // while (cur)
        // {
        //     if (!umap.count(cur))
        //     {
        //         umap[cur] = new Node(cur->val);
        //     }
        //     if (cur->next)
        //     {
        //         if (!umap.count(cur->next))
        //         {
        //             umap[cur->next] = umap[cur]->next = new Node(cur->next->val);
        //         }
        //         else
        //         {
        //             umap[cur]->next = umap[cur->next];
        //         }
        //     }
        //     if (cur->random)
        //     {
        //         if (!umap.count(cur->random))
        //         {
        //             umap[cur->random] = umap[cur]->random = new Node(cur->random->val);
        //         }
        //         else
        //         {
        //             umap[cur]->random = umap[cur->random];
        //         }
        //     }
        //     cur = cur->next;
        // }
        // return umap[head];
    }
};
// @lc code=end
