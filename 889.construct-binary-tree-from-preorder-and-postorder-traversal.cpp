/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
#include <vector>
using namespace std;
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
// t:O(N), s:O(N)
// if node val is available to be repeated, then another apporach is t:O(N^2)
class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int w = preorder.size();
        int pre_idx = 1;
        int post_idx = 0;
        TreeNode *root = new TreeNode(preorder[0]);
        auto cur = root;
        vector<TreeNode *> st = {root};
        while (pre_idx != w)
        {
            while (pre_idx != w && preorder[pre_idx - 1] != postorder[post_idx])
            {
                cur->left = new TreeNode(preorder[pre_idx]);
                ++pre_idx;
                cur = cur->left;
                st.push_back(cur);
            }
            if (pre_idx == w)
            {
                break;
            }
            while (post_idx != w && cur->val == postorder[post_idx])
            {
                ++post_idx;
                st.pop_back();
                cur = st.back();
            }
            cur->right = new TreeNode(preorder[pre_idx]);
            cur = cur->right;
            ++pre_idx;
            st.push_back(cur);
        }
        return root;
    }
};
// @lc code=end
