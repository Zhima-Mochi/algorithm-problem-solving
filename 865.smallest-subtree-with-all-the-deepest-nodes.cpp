/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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

// t:O(N), s:O(height)
class Solution
{
    int max_depth = 0;
    TreeNode *res;

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        postorder_get_depth(root, 0);
        return res;
    }
    int postorder_get_depth(TreeNode *node, int current_depth)
    {
        if (!node)
        {
            return 0;
        }
        int left_d = postorder_get_depth(node->left, current_depth + 1);
        int right_d = postorder_get_depth(node->right, current_depth + 1);
        int d = max(left_d, right_d);
        if (left_d == right_d && d + current_depth >= max_depth)
        {
            max_depth = d + current_depth;
            res = node;
        }
        return d + 1;
    }
};
// @lc code=end
