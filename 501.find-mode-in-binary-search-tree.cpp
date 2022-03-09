/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        int mode_count = 0;
        int cur_count = 0;
        int cur_val = root->val;
        auto dummy = new TreeNode(100001, root, nullptr);
        auto cur = dummy;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                helpler(cur_val, cur_count, res, mode_count, cur);
                cur = cur->right;
            }
            else
            {
                auto prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right != cur)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    helpler(cur_val, cur_count, res, mode_count, cur);
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        helpler(cur_val, cur_count, res, mode_count, dummy);
        return res;
    }
    void helpler(int &cur_val, int &cur_count, vector<int> &res, int &mode_count, TreeNode *cur)
    {
        if (cur->val == cur_val)
        {
            ++cur_count;
        }
        else
        {
            if (mode_count < cur_count)
            {
                res = vector<int>({cur_val});
                mode_count = cur_count;
            }
            else if (mode_count == cur_count)
            {
                res.push_back(cur_val);
            }
            cur_count = 1;
            cur_val = cur->val;
        }
    }
};
// @lc code=end
