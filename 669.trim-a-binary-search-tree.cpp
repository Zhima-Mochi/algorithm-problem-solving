/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        while (root && (root->val > high || root->val < low))
        {
            if (root->val > high)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        trimLow(root, low);
        trimHigh(root, high);
        return root;
    }
    void trimLow(TreeNode *node, int low)
    {
        if (!node)
        {
            return;
        }
        if (!node->left)
        {
            return;
        }
        else if (node->left->val > low)
        {
            trimLow(node->left, low);
        }
        else if (node->left->val == low)
        {
            node->left->left = nullptr;
        }
        else
        {
            node->left = node->left->right;
            trimLow(node, low);
        }
    }
    void trimHigh(TreeNode *node, int high)
    {
        if (!node)
        {
            return;
        }
        if (!node->right)
        {
            return;
        }
        else if (node->right->val < high)
        {
            trimHigh(node->right, high);
        }
        else if (node->right->val == high)
        {
            node->right->right = nullptr;
        }
        else
        {
            node->right = node->right->left;
            trimHigh(node, high);
        }
    }
};
// @lc code=end