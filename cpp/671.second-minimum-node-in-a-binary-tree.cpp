/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 */
#include <algorithm>
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
    int findSecondMinimumValue(TreeNode *root)
    {
        int minimum = root->val;
        long res = INT64_MAX;
        preOrder(root, res, minimum);
        return res == INT64_MAX ? -1 : res;
    }
    void preOrder(TreeNode *root, long &res, int &mininum)
    {
        if (!root)
        {
            return;
        }
        if (root->val > mininum)
        {
            res = min(res, static_cast<long>(root->val));
            return;
        }
        preOrder(root->left, res, mininum);
        preOrder(root->right, res, mininum);
    }
};
// @lc code=end
