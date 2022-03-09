/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
public:
    int getMinimumDifference(TreeNode *root)
    {
        auto cur = root;
        int prev_val = -20000;
        int res = 20000;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                res = min(cur->val - prev_val, res);
                prev_val = cur->val;
                cur = cur->right;
            }
            else
            {
                auto prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right != cur)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    res = min(cur->val - prev_val, res);
                    prev_val = cur->val;
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end
