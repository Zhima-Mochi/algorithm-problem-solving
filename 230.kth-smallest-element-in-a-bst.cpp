/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<TreeNode *> st;
        auto cur = root;
        while (true)
        {
            if (cur)
            {
                st.push_back(cur);
                cur = cur->left;
            }
            else if (!st.empty())
            {
                cur=st.back();
                st.pop_back();
                if (k == 1)
                {
                    return cur->val;
                }
                else
                {
                    --k;
                    cur = cur->right;
                }
            }
            else
            {
                break;
            }
        }
        return 0;
    }
};
// @lc code=end
