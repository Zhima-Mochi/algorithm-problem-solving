/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int q_len = q.size();
            vector<int> elem;
            while (q_len--)
            {
                auto cur = q.front();
                q.pop();
                elem.push_back(cur->val);
                for (auto n : cur->children)
                {
                    if (n)
                    {
                        q.push(n);
                    }
                }
            }
            res.push_back(elem);
        }
        return res;
    }
};
// @lc code=end
