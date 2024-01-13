/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
#include <functional>
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
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        int ans = 0;
        function<pair<int, bool>(TreeNode *)> farest = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                return pair<int, bool>{0, false};
            }
            auto p1 = farest(node->left);
            auto p2 = farest(node->right);
            int res = max(p1.first, p2.first) + 1;
            if (node->val == start)
            {
                ans = max(ans, max(p1.first, p2.first));
                return pair<int, bool>{0, true};
            }
            if (p1.second || p2.second)
            {
                ans = max(ans, p1.first + p2.first + 1);
            }
            if (p1.second)
            {
                return pair<int, bool>{p1.first + 1, true};
            }
            if (p2.second)
            {
                return pair<int, bool>{p2.first + 1, true};
            }
            return pair<int, bool>{res, false};
        };
        farest(root);
        return ans;
    }
};
// @lc code=end
