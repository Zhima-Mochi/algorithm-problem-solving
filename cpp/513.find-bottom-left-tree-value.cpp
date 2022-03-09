/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode *root)
    {
        vector<TreeNode *> st_node;
        vector<int> st_depth;
        int depth = 0;
        int max_depth = -1;
        int res = 0;
        auto cur = root;
        while (true)
        {
            if (cur)
            {
                ++depth;
                st_node.push_back(cur);
                st_depth.push_back(depth);
                cur = cur->left;
            }
            else if (!st_node.empty())
            {
                cur = st_node.back()->right;
                depth = st_depth.back();
                if (depth > max_depth)
                {
                    res = st_node.back()->val;
                    max_depth=depth;
                }
                st_node.pop_back();
                st_depth.pop_back();
            }else{
                break;
            }
        }
        return res;
    }
};
// @lc code=end
