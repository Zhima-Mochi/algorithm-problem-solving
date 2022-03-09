/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 */
#include <string>
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
// t:O(N), s:O(N)
class Solution
{
    string res = {127};

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string s = "";
        dfs_pre(root, s);
        return res;
    }
    void dfs_pre(TreeNode *node, string &s)
    {
        if (!node)
        {
            return;
        }
        s.push_back('a' + node->val);
        if (!node->left && !node->right)
        {
            reverse(s.begin(), s.end());
            res = min(res, s);
            reverse(s.begin(), s.end());
        }
        else
        {
            dfs_pre(node->left, s);
            dfs_pre(node->right, s);
        }
        s.pop_back();
    }
};
// @lc code=end
