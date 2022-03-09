/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */
#include <vector>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<double> res;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            long sum_val = 0;
            for (int i = 0; i != len; ++i)
            {
                auto cur = q.front();
                q.pop();
                sum_val += cur->val;
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
            res.push_back(static_cast<double>(sum_val) / len);
        }
        return res;
    }
};
// @lc code=end
