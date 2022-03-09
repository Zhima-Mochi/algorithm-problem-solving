/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
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
class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        int level = 0;
        vector<TreeNode *> level_nodes;
        level_nodes.push_back(root);
        while (!level_nodes.empty())
        {
            vector<TreeNode *> next_level_nodes;
            TreeNode *prev = nullptr;
            if (level % 2)
            {
                for (auto node : level_nodes)
                {
                    if (node->val % 2)
                    {
                        return false;
                    }
                    if (prev && node->val >= prev->val)
                    {
                        return false;
                    }
                    if (node->left)
                    {
                        next_level_nodes.push_back(node->left);
                    }
                    if (node->right)
                    {
                        next_level_nodes.push_back(node->right);
                    }
                    prev = node;
                }
            }
            else
            {
                for (auto node : level_nodes)
                {
                    if (node->val % 2 == 0)
                    {
                        return false;
                    }
                    if (prev && node->val <= prev->val)
                    {
                        return false;
                    }
                    if (node->left)
                    {
                        next_level_nodes.push_back(node->left);
                    }
                    if (node->right)
                    {
                        next_level_nodes.push_back(node->right);
                    }
                    prev = node;
                }
            }
            ++level;
            level_nodes = move(next_level_nodes);
        }
        return true;
    }
};
// @lc code=end
