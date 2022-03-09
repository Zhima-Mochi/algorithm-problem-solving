/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
// T:O(N log N) S:O(1)
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *root = new TreeNode(nums[0]);
        int width = nums.size();
        for (int i = 1; i != width; ++i)
        {
            if (nums[i] > root->val)
            {
                root = new TreeNode(nums[i], root, nullptr);
            }
            else
            {
                auto cur = root;
                while (cur->right != nullptr && nums[i] < cur->right->val)
                {
                    cur = cur->right;
                }
                cur->right = new TreeNode(nums[i], cur->right, nullptr);
            }
        }
        return root;
    }
};
// @lc code=end
