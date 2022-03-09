/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        queue<string> collection;
        collection.push(to_string(root->val));
        queue<TreeNode *> node_collection;
        node_collection.push(root);
        while (!node_collection.empty())
        {
            int len = node_collection.size();
            for (int i = 0; i != len; ++i)
            {
                auto &cur_node = node_collection.front();
                if (cur_node->left || cur_node->right)
                {
                    if (cur_node->left)
                    {
                        node_collection.push(cur_node->left);
                        collection.push(collection.front() + "->" + to_string(cur_node->left->val));
                    }
                    if (cur_node->right)
                    {
                        node_collection.push(cur_node->right);
                        collection.push(collection.front() + "->" + to_string(cur_node->right->val));
                    }
                }
                else
                {
                    res.push_back(collection.front());
                }
                node_collection.pop();
                collection.pop();
            }
        }
        return res;
    }
};
// @lc code=end
