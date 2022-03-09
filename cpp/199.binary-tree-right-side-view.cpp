/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            int q_len = q.size();
            for (int i = 0; i != q_len; ++i)
            {
                auto node = q.front();
                q.pop();
                if (node->right)
                {
                    q.push(node->right);
                }
                if (node->left)
                {
                    q.push(node->left);
                }
            }
        }
        return res;
    }
};
// @lc code=end
