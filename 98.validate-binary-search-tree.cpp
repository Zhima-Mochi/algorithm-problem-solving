/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
#include <stack>
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
    bool isValidBST(TreeNode *root)
    {
        auto cur = root;
        stack<TreeNode *> st;
        long min_val = static_cast<long>(1 << 31) - 1, max_val = static_cast<long>(~(1 << 31)) + 1;
        while (true)
        {
            if (cur)
            {
                if (min_val >= cur->val || max_val <= cur->val)
                {
                    return false;
                }
                st.push(cur);
                max_val = cur->val;
                cur = cur->left;
            }
            else if (!st.empty())
            {
                min_val = max_val;
                cur = st.top()->right;
                st.pop();
                if (!st.empty())
                {
                    max_val = st.top()->val;
                }
                else
                {
                    max_val = static_cast<long>(~(1 << 31)) + 1;
                }
            }
            else
            {
                break;
            }
        }
        return true;
    }
};
// @lc code=end
