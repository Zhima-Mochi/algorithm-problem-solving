/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode *root)
    {
        auto p = helpler(root);
        return max(p.first, p.second);
    }
    pair<int, int> helpler(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }
        auto left = helpler(root->left);
        auto right = helpler(root->right);
        auto pre_pre_max = left.second + right.second;
        auto pre_max = left.first + right.first;
        int temp = max(pre_max, pre_pre_max + root->val);
        pre_pre_max = pre_max;
        pre_max = temp;
        return {pre_max, pre_pre_max};
    }
};
// @lc code=end
