/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
 */
#include <cmath>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
// t:O(N), s:O(N)
class Solution
{
    int res = 0;
public:
    int distributeCoins(TreeNode *root)
    {
        dfs_post(root);
        return res;
    }
    int dfs_post(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        int left = dfs_post(node->left);
        int right = dfs_post(node->right);
        res += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
};
// @lc code=end
