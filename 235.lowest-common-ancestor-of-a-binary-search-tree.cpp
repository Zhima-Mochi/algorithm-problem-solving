/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int min_val = p->val;
        int max_val = q->val;
        if (min_val > max_val)
        {
            swap(min_val, max_val);
        }
        while (root)
        {
            if (root->val > max_val)
            {
                root = root->left;
            }
            else if (root->val < min_val)
            {
                root = root->right;
            }
            else
            {
                break;
            }
        }
        return root;
    }
};
// @lc code=end
