/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        auto row_head_cur = root;
        if (!root)
        {
            return root;
        }
        while (row_head_cur->left)
        {
            auto row_cur = row_head_cur;
            Node *prev_child = nullptr;
            while (row_cur)
            {
                if (prev_child)
                {
                    prev_child->next = row_cur->left;
                }
                row_cur->left->next = row_cur->right;
                prev_child = row_cur->right;
                row_cur = row_cur->next;
            }
            row_head_cur = row_head_cur->left;
        }
        return root;
    }
};
// @lc code=end
