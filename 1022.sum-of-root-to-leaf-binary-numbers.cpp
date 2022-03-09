/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int sumRootToLeaf(TreeNode *root)
    {
        auto cur = root;
        int cur_num = 0;
        int res = 0;
        vector<TreeNode *> st;
        vector<int> num_st;
        while (true)
        {
            if (cur)
            {
                cur_num <<= 1;
                cur_num += cur->val;
                st.push_back(cur);
                num_st.push_back(cur_num);
                cur = cur->left;
            }
            else if (!st.empty())
            {
                if (!st.back()->right && !st.back()->left)
                {
                    res += num_st.back();
                }
                cur = st.back()->right;
                cur_num = num_st.back();
                st.pop_back();
                num_st.pop_back();
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
