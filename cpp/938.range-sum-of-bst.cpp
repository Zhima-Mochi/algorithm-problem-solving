/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        vector<TreeNode *> st;
        auto cur = root;
        int res = 0;
        //consider value are not unique
        while (true)
        {
            if (cur)
            {
                if (cur->val < low)
                {
                    cur = cur->right;
                }
                else
                {
                    st.push_back(cur);
                    cur = cur->left;
                }
            }
            else if (!st.empty())
            {
                if (st.back()->val <= high)
                {
                    res += st.back()->val;
                    cur = st.back()->right;
                }
                else
                {
                    cur = nullptr;
                }
                st.pop_back();
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
