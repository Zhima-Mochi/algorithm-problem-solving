/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */
#include <stack>
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
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> left, right;
        TreeNode *cur_left = root->left, *cur_right = root->right;
        while (true)
        {
            if (cur_left == nullptr || cur_right == nullptr)
            {
                if (cur_left != cur_right)
                {
                    return false;
                }
                else
                {
                    if (left.empty())
                    {
                        return true;
                    }
                    else
                    {
                        cur_left = left.top()->right;
                        left.pop();
                        cur_right = right.top()->left;
                        right.pop();
                    }
                }
            }
            else
            {
                if (cur_left->val == cur_right->val)
                {
                    left.push(cur_left);
                    right.push(cur_right);
                    cur_left = cur_left->left;
                    cur_right = cur_right->right;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};
// @lc code=end
