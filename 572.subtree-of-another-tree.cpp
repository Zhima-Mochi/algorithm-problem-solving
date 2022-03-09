/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return preOrder(root, subRoot);
    }
    bool preOrder(TreeNode *root, TreeNode *subRoot)
    {
        if (checkSubtree(root, subRoot))
        {
            return true;
        }
        if (!root)
        {
            return false;
        }
        return preOrder(root->left, subRoot) || preOrder(root->right, subRoot);
    }
    bool checkSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
        {
            return true;
        }
        else if (root && !subRoot || !root && subRoot)
        {
            return false;
        }
        if (root->val != subRoot->val)
        {
            return false;
        }
        return checkSubtree(root->left, subRoot->left) && checkSubtree(root->right, subRoot->right);
    }
};
// @lc code=end
