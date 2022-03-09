/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> collection;
        collection.push(root);
        while (!collection.empty())
        {
            res.push_back(vector<int>());
            auto &sub_col = res.back();
            int len = collection.size();
            for (int i = 0; i != len; ++i)
            {
                auto ft = collection.front();
                collection.pop();
                sub_col.push_back(ft->val);
                if (ft->left)
                {
                    collection.push(ft->left);
                }
                if (ft->right)
                {
                    collection.push(ft->right);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
