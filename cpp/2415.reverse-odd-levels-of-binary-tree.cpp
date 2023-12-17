/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
#include <deque>
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
// t:O(n), s:O(n)
class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        int deep = 0;
        deque<TreeNode *> same_level_nodes;
        same_level_nodes.push_back(root);
        while (!same_level_nodes.empty())
        {
            int sz = same_level_nodes.size();
            if (deep % 2)
            {
                for (int i = 0; i != sz / 2; ++i)
                {
                    swap(same_level_nodes[i]->val, same_level_nodes[sz - 1 - i]->val);
                }
            }
            while (sz--)
            {
                auto node = same_level_nodes[0];
                same_level_nodes.pop_front();
                if (node->left)
                {
                    same_level_nodes.push_back(node->left);
                }
                if (node->right)
                {
                    same_level_nodes.push_back(node->right);
                }
            }
            deep += 1;
        }
        return root;
    }
};
// @lc code=end
