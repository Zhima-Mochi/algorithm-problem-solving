/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    unordered_map<string, int> seen;
    vector<TreeNode *> res;

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        post_order_traversal(root);
        return res;
    }
    string post_order_traversal(TreeNode *node)
    {
        if (!node)
        {
            return "";
        }
        string l = post_order_traversal(node->right);
        string r = post_order_traversal(node->left);
        string comb = to_string(node->val) + '<' + l + '>' + r;
        ++seen[comb];
        if (seen[comb] == 2)
        {
            res.push_back(node);
        }
        return comb;
    }
};
// @lc code=end
