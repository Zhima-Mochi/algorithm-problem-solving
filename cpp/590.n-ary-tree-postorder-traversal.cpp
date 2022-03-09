/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */
#include <vector>
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
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        postorderCollection(root, res);
        return res;
    }
    void postorderCollection(Node *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        for (auto child : root->children)
        {
            postorderCollection(child, res);
        }
        res.push_back(root->val);
    }
};
// @lc code=end
