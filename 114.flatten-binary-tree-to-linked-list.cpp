/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root)
    {
        auto cur = root;
        while (cur)
        {
            if (cur->left != nullptr)
            {
                auto prev = cur->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
        // auto cur = root;
        // TreeNode *bottom_cur = nullptr;
        // while (cur)
        // {

        //     if (cur->left == nullptr)
        //     {
        //         cur->left = cur->right;
        //         bottom_cur = cur;
        //         cur = cur->left;
        //     }
        //     else
        //     {
        //         auto prev = cur->left;
        //         while (prev->right != cur && prev->right)
        //         {
        //             prev = prev->right;
        //         }
        //         if (prev->right == nullptr)
        //         {
        //             prev->right = cur;
        //             cur = cur->left;
        //         }
        //         else
        //         {
        //             prev->right = nullptr;
        //             bottom_cur->left = cur->right;
        //             cur = cur->right;
        //         }
        //     }
        // }
        // cur = root;
        // while (cur)
        // {
        //     cur->right=cur->left;
        //     cur->left=nullptr;
        //     cur = cur->right;
        // }
    }
};
// @lc code=end
