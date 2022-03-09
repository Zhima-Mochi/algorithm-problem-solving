/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        auto dummy = new TreeNode(0, root, nullptr);
        auto cur = dummy;
        vector<TreeNode *> node_stack;
        vector<int> depth_stack;
        int cur_depth = 0;
        while (true)
        {
            if (cur && cur_depth == depth - 1)
            {
                cur->left = new TreeNode(val, cur->left, nullptr);
                cur->right = new TreeNode(val, nullptr, cur->right);
                cur = nullptr;
            }
            if (cur)
            {
                ++cur_depth;
                depth_stack.push_back(cur_depth);
                node_stack.push_back(cur);
                cur = cur->left;
            }
            else if (!node_stack.empty())
            {
                cur_depth = depth_stack.back();
                cur = node_stack.back()->right;
                node_stack.pop_back();
                depth_stack.pop_back();
            }
            else
            {
                break;
            }
        }
        return dummy->left;
    }
};
// @lc code=end
