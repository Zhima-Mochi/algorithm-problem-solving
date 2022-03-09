/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
#include <vector>
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
class Solution
{
    int res = 0;

public:
    int maxAncestorDiff(TreeNode *root)
    {
        helpler(root);
        return res;
    }
    vector<int> helpler(TreeNode *node)
    {
        if (!node)
        {
            return {INT_MAX, INT_MIN};
        }
        auto v = helpler(node->left);
        auto right_child_range = helpler(node->right);
        v[0] = min({v[0], node->val, right_child_range[0]});
        v[1] = max({v[1], node->val, right_child_range[1]});
        res = max({res, v[1] - node->val, node->val - v[0]});
        return v;
    }
};
// @lc code=end
