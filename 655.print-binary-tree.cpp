/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
 */
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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
    int height;

public:
    vector<vector<string>> printTree(TreeNode *root)
    {
        height = find_height(root);
        int n = round(pow(2, height + 1)) - 1;
        vector<vector<string>> res(height + 1, vector<string>(n));
        preorder_trasversal(res, root, 0, (n - 1) / 2);
        return res;
    }
    int find_height(TreeNode *node)
    {
        if (!node)
        {
            return -1;
        }
        return 1 + max(find_height(node->left), find_height(node->right));
    }
    void preorder_trasversal(vector<vector<string>> &res, TreeNode *node, int depth, int pos)
    {
        if (!node)
        {
            return;
        }
        res[depth][pos] = to_string(node->val);
        preorder_trasversal(res, node->left, depth + 1, pos - round(pow(2, height - depth - 1)));
        preorder_trasversal(res, node->right, depth + 1, pos + round(pow(2, height - depth - 1)));
    }
};
// @lc code=end
