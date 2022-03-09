/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <vector>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// t:O(n), s:O(maximum height of tree) 
class Solution
{
    vector<int> res;

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        findDistanceVal(target, k);
        vector<pair<TreeNode *, int>> st;
        if (k > 0)
        {
            postOrder(root, target, k);
        }
        return res;
    }
    int postOrder(TreeNode *node, TreeNode *target, int distance)
    {
        if (!node)
        {
            return 0;
        }
        if (node == target)
        {
            return 1;
        }
        int d_left = postOrder(node->left, target, distance);
        int d_right = d_left > 0 ? 0 : postOrder(node->right, target, distance);
        int d = d_left + d_right;

        if (d == distance)
        {
            findDistanceVal(node, 0);
        }
        else if (d_left > 0)
        {
            findDistanceVal(node->right, distance - d_left - 1);
        }
        else if (d_right > 0)
        {
            findDistanceVal(node->left, distance - d_right - 1);
        }
        return d == 0 ? 0 : d + 1;
    }
    void findDistanceVal(TreeNode *node, int distance)
    {
        auto cur = node;
        vector<pair<TreeNode *, int>> st;
        int d = 0;
        while (true)
        {
            if (d == distance)
            {
                if (cur)
                {
                    res.push_back(cur->val);
                }
            }
            if (cur && d < distance)
            {
                st.push_back({cur, d});
                cur = cur->left;
                ++d;
            }
            else if (!st.empty())
            {
                cur = st.back().first->right;
                d = st.back().second + 1;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
    }
};
// @lc code=end
