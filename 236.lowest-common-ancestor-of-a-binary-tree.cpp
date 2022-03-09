/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> st, second_st;
        auto cur = root;
        TreeNode *res = root;
        bool first_find = false;
        while (true)
        {
            if (cur)
            {
                if (cur == p || cur == q)
                {
                    if (first_find)
                    {
                        return res;
                    }
                    else
                    {
                        first_find = true;
                        res = cur;
                        second_st.push_back(cur);
                    }
                }
                else
                {
                    if (first_find)
                    {
                        second_st.push_back(cur);
                    }
                    else
                    {
                        st.push_back(cur);
                    }
                }
                cur = cur->left;
            }
            else if (!second_st.empty())
            {
                cur = second_st.back()->right;
                second_st.pop_back();
            }
            else if (!st.empty())
            {
                cur = st.back()->right;
                res = st.back();
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
