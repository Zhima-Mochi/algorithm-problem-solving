/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        vector<TreeNode *> collection = {root};
        while (collection.size())
        {
            vector<TreeNode *> next_collection;
            res.push_back(vector<int>());
            auto &sub_collect = res.back();
            for (auto &c : collection)
            {
                sub_collect.push_back(c->val);
                if (c->left)
                {
                    next_collection.push_back(c->left);
                }
                if (c->right)
                {
                    next_collection.push_back(c->right);
                }
            }
            collection.swap(next_collection);
        }
        return res;
    }
};
// @lc code=end
