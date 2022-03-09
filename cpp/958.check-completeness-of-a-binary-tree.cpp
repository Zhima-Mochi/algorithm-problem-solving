/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
// t:O(N), s:O(height)
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        vector<pair<TreeNode *, int>> st;
        auto cur = root;
        int d = 0;
        int max_d = -1;
        bool no_max_d = false;
        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push_back({cur, d});
                cur = cur->left;
                ++d;
            }
            else
            {
                if (d > max_d)
                {
                    if (max_d == -1)
                    {
                        max_d = d;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (d == max_d)
                {
                    if (no_max_d)
                    {
                        return false;
                    }
                }
                else if (d == max_d - 1)
                {
                    no_max_d = true;
                }
                else
                {
                    return false;
                }
                cur = st.back().first->right;
                d = st.back().second + 1;
                st.pop_back();
            }
        }
        if (d > max_d)
        {
            if (max_d == -1)
            {
                max_d = d;
            }
            else
            {
                return false;
            }
        }
        else if (d == max_d)
        {
            if (no_max_d)
            {
                return false;
            }
        }
        else if (d == max_d - 1)
        {
            no_max_d = true;
        }
        else
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
