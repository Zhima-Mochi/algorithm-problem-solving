/*
 * @lc app=leetcode id=998 lang=cpp
 *
 * [998] Maximum Binary Tree II
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <climits>
using namespace std;
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
// t:O(N), s:O(1)
class Solution
{
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        auto dummy = new TreeNode(INT_MAX, nullptr, root);
        auto cur = dummy;
        auto appended = new TreeNode(val);
        while (true)
        {
            if (!cur->right)
            {
                cur->right = appended;
                break;
            }
            else if (cur->right->val < val)
            {
                appended->left = cur->right;
                cur->right = appended;
                break;
            }
            cur = cur->right;
        }
        auto res = dummy->right;
        delete (dummy);
        return res;
    }
};
// @lc code=end
