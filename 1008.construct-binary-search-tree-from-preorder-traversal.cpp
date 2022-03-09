/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        auto cur = root;
        vector<TreeNode *> node_stack = {root};
        for (int i = 1, width = preorder.size(); i != width; ++i)
        {
            int cur_val = preorder[i];
            if (node_stack.back()->val > cur_val)
            {
                cur->left = new TreeNode(cur_val);
                cur = cur->left;
                node_stack.push_back(cur);
            }
            else
            {
                while (!node_stack.empty() && node_stack.back()->val < cur_val)
                {
                    cur = node_stack.back();
                    node_stack.pop_back();
                }
                cur->right = new TreeNode(cur_val);
                cur = cur->right;
                node_stack.push_back(cur);
            }
        }
        return root;
    }
};
// @lc code=end
