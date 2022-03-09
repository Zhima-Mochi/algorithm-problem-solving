/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
#include <functional>
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
public:
    int maxPathSum(TreeNode *root)
    {
        int res = -1000;
        function<int(TreeNode *)> postorder = [&](TreeNode *node)
        {
            if (!node)
            {
                return 0;
            }
            int left_val = postorder(node->left);
            int righ_val = postorder(node->right);
            res = max(res, left_val + righ_val + node->val);
            return max(max(left_val, righ_val) + node->val, 0);
        };
        postorder(root);
        return res;
    }
};
// @lc code=end
