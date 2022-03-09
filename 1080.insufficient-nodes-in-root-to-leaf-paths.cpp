/*
 * @lc app=leetcode id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
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
// t:O(N), s:O(N)
class Solution
{
    int lim;

public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        lim = limit;
        TreeNode *dummy = new TreeNode(0, root, nullptr);
        dfs_maximum_root_to_leaf(dummy, 0);
        return dummy->left;
    }
    void dfs_accumulate(TreeNode *node, int sum_val)
    {
        if (!node)
        {
            return;
        }
        node->val += sum_val;
        dfs_accumulate(node->left, node->val);
        dfs_accumulate(node->right, node->val);
    }
    int dfs_maximum_root_to_leaf(TreeNode *node, int sum_val)
    {
        if (!node)
        {
            return 1 << 31;
        }
        sum_val += node->val;
        if (!node->left && !node->right)
        {
            return sum_val;
        }
        int left_val = dfs_maximum_root_to_leaf(node->left, sum_val);
        int right_val = dfs_maximum_root_to_leaf(node->right, sum_val);
        if (left_val < lim)
        {
            node->left = nullptr;
        }
        if (right_val < lim)
        {
            node->right = nullptr;
        }
        return max(left_val, right_val);
    }
};
// @lc code=end
// class Solution
// {
//     int lim;

// public:
//     TreeNode *sufficientSubset(TreeNode *root, int limit)
//     {
//         lim = limit;
//         TreeNode *dummy = new TreeNode(0, root, nullptr);
//         dfs_accumulate(dummy, 0);
//         dfs_maximum_root_to_leaf(dummy);
//         dfs_back_to_origin(dummy, 0);
//         return dummy->left;
//     }
//     void dfs_accumulate(TreeNode *node, int sum_val)
//     {
//         if (!node)
//         {
//             return;
//         }
//         node->val += sum_val;
//         dfs_accumulate(node->left, node->val);
//         dfs_accumulate(node->right, node->val);
//     }
//     void dfs_back_to_origin(TreeNode *node, int parent_sum)
//     {
//         if (!node)
//         {
//             return;
//         }
//         dfs_back_to_origin(node->left, node->val);
//         dfs_back_to_origin(node->right, node->val);
//         node->val -= parent_sum;
//     }
//     int dfs_maximum_root_to_leaf(TreeNode *node)
//     {
//         if (!node)
//         {
//             return 1 << 31;
//         }
//         if (!node->left && !node->right)
//         {
//             return node->val;
//         }
//         int left_val = dfs_maximum_root_to_leaf(node->left);
//         int right_val = dfs_maximum_root_to_leaf(node->right);
//         if (left_val < lim)
//         {
//             node->left = nullptr;
//         }
//         if (right_val < lim)
//         {
//             node->right = nullptr;
//         }
//         return max(left_val, right_val);
//     }
// };