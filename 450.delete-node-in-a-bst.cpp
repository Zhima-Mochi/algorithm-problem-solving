/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */
#include <functional>
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *head = new TreeNode(INT32_MAX, root, nullptr), *cur = root, *prev = head;
        while (cur)
        {
            if (cur->val == key)
            {
                break;
            }
            prev = cur;
            if (cur->val > key)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        if (!cur)
        {
            return root;
        }

        bool in_left = prev->left == cur;
        TreeNode *sub_cur = nullptr;
        if (cur->left && cur->right)
        {
            sub_cur = cur->left;
            if (!sub_cur->right)
            {
                sub_cur->right = cur->right;
            }
            else
            {
                auto sub_prev = sub_cur;
                sub_cur = sub_cur->right;
                while (sub_cur->right)
                {
                    sub_prev = sub_cur;
                    sub_cur = sub_cur->right;
                }
                sub_prev->right = sub_cur->left;
                sub_cur->left = cur->left;
                sub_cur->right = cur->right;
            }
        }
        else if (cur->left)
        {
            sub_cur = cur->left;
        }
        else if (cur->right)
        {
            sub_cur = cur->right;
        }
        
        if (in_left)
        {
            prev->left = sub_cur;
        }
        else
        {
            prev->right = sub_cur;
        }
        return head->left;
    }
};
// @lc code=end
