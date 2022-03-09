/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */
#include <cmath>
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
    int countNodes(TreeNode *root)
    {
        int res = 0;
        auto cur = root;
        auto left = left_depth(cur);
        auto right = right_depth(cur);
        res += pow(2, right) + 0.5 - 1;
        while (left != right)
        {
            --left, --right;
            auto mid = right_depth(cur->left);
            if (mid == left)
            {
                res += pow(2, mid - 1) + 0.5;
                cur = cur->right;
                left = left_depth(cur);
            }
            else
            {
                cur = cur->left;
            }
        }
        return res;
    }

    int right_depth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int i = 1;
        while (root->right)
        {
            root = root->right;
            ++i;
        }
        return i;
    }
    int left_depth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int i = 1;
        while (root->left)
        {
            root = root->left;
            ++i;
        }
        return i;
    }
};
// @lc code=end
