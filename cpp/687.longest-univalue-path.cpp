/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
    int res = 0;

public:
    int longestUnivaluePath(TreeNode *root)
    {
        postOrder(root, -1);
        return res;
    }
    int postOrder(TreeNode *node, int preVal)
    {
        if (!node)
        {
            return 0;
        }
        if (node->val == preVal)
        {
            int left = postOrder(node->left, preVal);
            int right = postOrder(node->right, preVal);
            res = max(res, left + right);
            return 1 + max(left, right);
        }
        else
        {
            res = max(res, postOrder(node->left, node->val) + postOrder(node->right, node->val));
            return 0;
        }
    }
};
// @lc code=end
