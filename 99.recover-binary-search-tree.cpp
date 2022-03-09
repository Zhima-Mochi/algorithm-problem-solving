/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode *root)
    {
        auto cur = root;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *minimum = nullptr;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                if (minimum && minimum->val >= cur->val)
                {
                    if (!first)
                    {
                        first = minimum;
                        second = cur;
                    }
                    else
                    {
                        second = cur;
                    }
                }
                minimum=cur;
                cur = cur->right;
            }
            else
            {
                auto prev = cur->left;
                while (prev->right != nullptr && prev->right != cur)
                    prev = prev->right;
                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = nullptr;
                    if (minimum && minimum->val >= cur->val)
                    {
                        if (!first)
                        {
                            first = minimum;
                            second = cur;
                        }
                        else
                        {
                            second = cur;
                        }
                    }
                    minimum=cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
        return;
    }
};
// @lc code=end
//[3,null,1,2]\n[1,3,null,2,null,4]\n[2,null,1,null,3]\n[1,2,null,3]\n[2,3,1]\n[3,null,2,null,1]
