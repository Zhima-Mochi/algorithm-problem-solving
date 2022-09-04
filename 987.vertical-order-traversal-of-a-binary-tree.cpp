/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */
#include<vector>
#include<queue>
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<TreeNode *> seen;
        queue<int> col_pos;
        seen.push(root);
        col_pos.push(0);
        vector<vector<int>> record;
        int row = 0;
        while (!seen.empty())
        {
            int q_len = seen.size();
            for (int i = 0; i != q_len; ++i)
            {
                auto pos = col_pos.front();
                col_pos.pop();
                auto cur = seen.front();
                seen.pop();
                record.push_back({pos, row, cur->val});
                if (cur->left)
                {
                    seen.push(cur->left);
                    col_pos.push(pos - 1);
                }
                if (cur->right)
                {
                    seen.push(cur->right);
                    col_pos.push(pos + 1);
                }
            }
            ++row;
        }
        sort(record.begin(), record.end());
        auto shift = -record[0][0];
        vector<vector<int>> res(record.back()[0] + shift + 1);
        for (auto &v : record)
        {
            res[v[0] + shift].push_back(v[2]);
        }
        return res;
    }
};
// @lc code=end
