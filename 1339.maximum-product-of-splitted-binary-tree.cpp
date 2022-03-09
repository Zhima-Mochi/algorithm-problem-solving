/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
#define mod 1000000007
class Solution
{
public:
    int maxProduct(TreeNode *root)
    {
        nodeSum(root);
        vector<TreeNode *> st;
        auto cur = root;
        int sum_val = root->val;
        int diff = sum_val;
        while (true)
        {
            if (cur)
            {
                auto candidate_val = cur->val * 2 - sum_val;
                if (abs(candidate_val) < diff)
                {
                    diff = abs(candidate_val);
                }
                if (candidate_val < 0)
                {
                    cur = nullptr;
                }
                else if (candidate_val == 0)
                {
                    break;
                }
                else
                {
                    st.push_back(cur);
                    cur = cur->left;
                }
            }
            else if (!st.empty())
            {
                cur = st.back()->right;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        return (static_cast<long>(sum_val - diff) / 2 % mod) * static_cast<long>(((sum_val - diff) / 2 + diff) % mod) % mod;
    }
    void nodeSum(TreeNode *cur)
    {
        if (!cur)
        {
            return;
        }
        nodeSum(cur->left);
        nodeSum(cur->right);
        if (cur->left)
        {
            cur->val += cur->left->val;
        }
        if (cur->right)
        {
            cur->val += cur->right->val;
        }
    }
};
// @lc code=end
