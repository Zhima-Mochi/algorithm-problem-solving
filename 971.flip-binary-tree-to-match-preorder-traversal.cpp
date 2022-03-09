/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
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
class Solution
{
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> res;
        vector<TreeNode *> st;
        auto cur = root;
        if (cur->val != voyage[0])
        {
            return {-1};
        }
        int voyage_idx = 1;
        while (cur || !st.empty())
        {
            if (cur)
            {
                if (cur->right && cur->right->val == voyage[voyage_idx])
                {
                    swap(cur->left, cur->right);
                    if (cur->right)
                    {
                        res.push_back(cur->val);
                    }
                    ++voyage_idx;
                }
                else if (cur->left && cur->left->val != voyage[voyage_idx])
                {
                    return {-1};
                }
                else if (cur->left)
                {
                    ++voyage_idx;
                }
                st.push_back(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.back()->right;
                st.pop_back();
                if (cur && cur->val != voyage[voyage_idx])
                {
                    return {-1};
                }
                if (cur)
                {
                    ++voyage_idx;
                }
            }
        }
        return res;
    }
};
// @lc code=end
