/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */
#include <unordered_map>
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
    unordered_map<int, int> past_sum = {{0, 1}};

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int res = 0;
        preorderTras(res, root, targetSum, 0);
        return res;
    }
    void preorderTras(int &res, TreeNode *root, const int &targetSum, int current_sum)
    {
        if (!root)
        {
            return;
        }
        current_sum += root->val;
        if (past_sum.count(current_sum - targetSum))
        {
            res += past_sum[current_sum - targetSum];
        }
        ++past_sum[current_sum];
        preorderTras(res, root->left, targetSum, current_sum);
        preorderTras(res, root->right, targetSum, current_sum);
        --past_sum[current_sum];
    }
};
// @lc code=end
