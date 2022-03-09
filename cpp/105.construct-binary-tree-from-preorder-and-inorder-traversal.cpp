/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        auto pre_root = new TreeNode(5000);
        pre_root->left = new TreeNode();
        auto cur = pre_root->left;
        pre_root->left->right = pre_root;
        int preorder_cur = 0, inorder_cur = 0;
        int len = preorder.size();
       
        while (preorder_cur != len)
        {
            cur->val = preorder[preorder_cur];
            while (preorder[preorder_cur] != inorder[inorder_cur])
            {
                ++preorder_cur;
                cur->left = new TreeNode(preorder[preorder_cur]);
                cur->left->right = cur;
                cur = cur->left;
            }
            
            ++preorder_cur;
            ++inorder_cur;
            while (inorder_cur != len && cur->right->val == inorder[inorder_cur])
            {
                auto prev = cur->right;
                cur->right = nullptr;
                ++inorder_cur;
                cur = prev;
            }
            
            
            if (preorder_cur != len)
            {
                auto prev = cur->right;
                cur->right = new TreeNode();
                cur = cur->right;
                cur->right = prev;
            
            }
            else
            {
                
                auto prev = cur->right;
                cur->right = nullptr;
                cur = prev;
            }
        }
        
        while (cur != pre_root)
        {
            auto prev = cur->right;
            cur->right = nullptr;
            cur = prev;
        }
        return pre_root->left;
    }
};
// @lc code=end
