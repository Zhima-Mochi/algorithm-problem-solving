/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */
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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, long long>> node_pos_queue;
        node_pos_queue.push({root, 0});
        long long res = 0;
        while (!node_pos_queue.empty())
        {
            int q_len = node_pos_queue.size();
            res = max(res, node_pos_queue.back().second - node_pos_queue.front().second);
            int shift = node_pos_queue.front().second;
            while (q_len--)
            {
                auto elem = node_pos_queue.front();
                node_pos_queue.pop();
                if (elem.first->left)
                {
                    node_pos_queue.push({elem.first->left, (elem.second - shift) * 2});
                }
                if (elem.first->right)
                {
                    node_pos_queue.push({elem.first->right, (elem.second - shift) * 2 + 1});
                }
            }
        }
        return res + 1;
    }
};
// @lc code=end
