/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    TreeNode *increasingBST(TreeNode *root)
    {
        auto new_root = root;
        while (new_root->left)
        {
            new_root = new_root->left;
        }
        increasingBST(root, nullptr);
        return new_root;
    }
    void increasingBST(TreeNode *root, TreeNode *prev_cur)
    {
        if (!root)
        {
            return;
        }
        increasingBST(root->left, root);
        root->left = nullptr;
        if (!root->right)
        {
            root->right = prev_cur;
        }
        else
        {
            auto temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            increasingBST(root->right, prev_cur);
            root->right = temp;
        }
    }
};
// @lc code=end
// class Solution
// {
// public:
//     TreeNode *increasingBST(TreeNode *root)
//     {
//         TreeNode *new_root = new TreeNode();
//         auto cur = root, new_cur = new_root;
//         vector<TreeNode *> st;
//         while (true)
//         {
//             if (cur)
//             {
//                 st.push_back(cur);
//                 cur = cur->left;
//             }
//             else if (!st.empty())
//             {
//                 new_cur->right = st.back();
//                 new_cur = new_cur->right;
//                 new_cur->left = nullptr;
//                 cur = st.back()->right;
//                 st.pop_back();
//             }
//             else
//             {
//                 break;
//             }
//         }
//         return new_root->right;
//     }
// };