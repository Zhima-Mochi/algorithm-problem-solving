/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 */
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (x > y)
        {
            swap(x, y);
        }
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            int q_len = q.size();
            bool x_match = false, y_match = false;
            while (q_len)
            {
                auto l_c = q.front();
                q.pop();
                auto r_c = q.front();
                q.pop();
                if (l_c && r_c)
                {
                    if (l_c->val > r_c->val)
                    {
                        swap(l_c, r_c);
                    }
                    if (l_c->val == x && r_c->val == y)
                    {
                        return false;
                    }
                }
                if (l_c && l_c->val == x || r_c && r_c->val == x)
                {
                    x_match = true;
                }
                if (l_c && l_c->val == y || r_c && r_c->val == y)
                {
                    y_match = true;
                }

                if (x_match && y_match)
                {
                    return true;
                }
                insertQ(l_c, q);
                insertQ(r_c, q);
                q_len -= 2;
            }
            if (x_match || y_match)
            {
                return false;
            }
        }
        return false;
    }
    void insertQ(TreeNode *node, queue<TreeNode *> &q)
    {
        if (node)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
};
// @lc code=end
