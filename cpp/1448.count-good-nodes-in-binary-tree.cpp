/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        int cur_max = root->val;
        auto cur = root;
        vector<TreeNode *> st;
        while (true)
        {
            if (cur)
            {
                st.push_back(cur);
                if (cur->val >= cur_max)
                {
                    ++count;
                    cur_max = cur->val;
                }
                else
                {
                    cur->val = cur_max;
                }
                cur = cur->left;
            }
            else if (!st.empty())
            {
                cur = st.back()->right;
                cur_max = st.back()->val;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        return count;
    }
};
// @lc code=end
