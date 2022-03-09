/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        auto pre_root = new TreeNode(5000);
        pre_root->right = new TreeNode();
        auto cur = pre_root->right;
        pre_root->right->left = pre_root;
        int len = postorder.size();
        int postorder_cur = len - 1, inorder_cur = len - 1;

        while (postorder_cur != -1)
        {
            cur->val = postorder[postorder_cur];
            while (postorder[postorder_cur] != inorder[inorder_cur])
            {
                --postorder_cur;
                cur->right = new TreeNode(postorder[postorder_cur]);
                cur->right->left = cur;
                cur = cur->right;
            }

            --postorder_cur;
            --inorder_cur;
            while (inorder_cur != -1 && cur->left->val == inorder[inorder_cur])
            {
                auto prev = cur->left;
                cur->left = nullptr;
                --inorder_cur;
                cur = prev;
            }

            if (postorder_cur != -1)
            {
                auto prev = cur->left;
                cur->left = new TreeNode();
                cur = cur->left;
                cur->left = prev;
            }
            else
            {
                auto prev = cur->left;
                cur->left = nullptr;
                cur = prev;
            }
        }

        while (cur != pre_root)
        {
            auto prev = cur->left;
            cur->left = nullptr;
            cur = prev;
        }
        return pre_root->right;
    }
};
// @lc code=end
