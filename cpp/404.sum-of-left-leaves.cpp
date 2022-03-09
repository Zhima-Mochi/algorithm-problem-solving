/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        auto res = 0;
        if (!(root->left || root->right))
        {
            return res;
        }
        auto pre_root = new TreeNode();
        pre_root->left = root;
        auto cur = pre_root;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                cur = cur->right;
                if (cur->left && cur->left->right == cur)
                {
                    res += (cur->left->val);
                }
            }
            else
            {
                auto prev = cur->left;
                while (prev->right != cur && prev->right != nullptr)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end
