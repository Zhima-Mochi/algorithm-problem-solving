/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */
#include <vector>
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
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        auto cur = root;
        if (!cur)
        {
            return new TreeNode(val);
        }
        while (true)
        {
            if (val > cur->val)
            {
                if (!cur->right)
                {
                    cur->right = new TreeNode(val);
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
            else
            {
                if (!cur->left)
                {
                    cur->left = new TreeNode(val);
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
        }
        return root;
    }
};
// @lc code=end
