/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    TreeNode *convertBST(TreeNode *root)
    {
        vector<TreeNode *> st;
        auto cur = root;
        int accum_val = 0;
        // inorder traversal
        while (true)
        {
            if (cur)
            {
                st.push_back(cur);
                cur = cur->right;
            }
            else if (!st.empty())
            {
                accum_val = st.back()->val += accum_val;
                cur = st.back()->left;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        return root;
    }
};
// @lc code=end
