/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */
#include <stack>
#include <algorithm>
#include <climits>
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
    int minDiffInBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        auto cur = root;
        int res = INT_MAX;
        int pre_val = -100000;
        while (true)
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else if (!st.empty())
            {
                res = min(res, st.top()->val - pre_val);
                pre_val = st.top()->val;
                cur = st.top()->right;
                st.pop();
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
