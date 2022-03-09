/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> bfs;
        if (root)
        {
            bfs.push(root);
        }
        vector<int> res;
        while (!bfs.empty())
        {
            int bfs_len = bfs.size();
            int max_val = INT_MIN;
            while (bfs_len--)
            {
                auto &node = bfs.front();
                if (node->val > max_val)
                {
                    max_val = node->val;
                }
                if (node->left)
                {
                    bfs.push(node->left);
                }
                if (node->right)
                {
                    bfs.push(node->right);
                }
                bfs.pop();
            }
            res.push_back(max_val);
        }
        return res;
    }
};
// @lc code=end
