/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */
#include <vector>
#include <deque>
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        vector<TreeNode *> nodeVec = {root};
        auto depth = 1;
        while (true)
        {
            if (nodeVec.empty())
            {
                break;
            }
            vector<TreeNode *> new_vec;
            for (auto &cur : nodeVec)
            {
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    return depth;
                }
                else
                {
                    if (cur->left != nullptr)
                    {
                        new_vec.push_back(cur->left);
                    }

                    if (cur->right != nullptr)
                    {
                        new_vec.push_back(cur->right);
                    }
                }
            }
            depth++;
            nodeVec = new_vec;
        }
        return depth;
    }
};
// @lc code=end
