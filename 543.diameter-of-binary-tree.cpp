/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */
#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        postOrderHeight(root, res);
        return res;
    }
    int postOrderHeight(TreeNode *root, int &maxDiam)
    {
        if (root == nullptr)
        {
            return 0;
        }
        auto left_H = root->left ? postOrderHeight(root->left, maxDiam) : 0;
        auto right_H = root->right ? postOrderHeight(root->right, maxDiam) : 0;
        maxDiam = max(maxDiam, left_H + right_H);
        return max(left_H, right_H) + 1;
    }
};
// @lc code=end
