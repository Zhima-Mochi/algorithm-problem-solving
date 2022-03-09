/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        vector<int> sum_val = {0};
        vector<int> current_vec;
        vector<int> current_vec_length;
        TreeNode *cur = root, *prev_cur = nullptr;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                sum_val.push_back(sum_val.back());
                sum_val.back() += cur->val;
                current_vec.push_back(cur->val);
                //current_vec_length.push_back(current_vec.size());
                prev_cur = cur;
                cur = cur->right;
            }
            else
            {
                auto prev = cur->left;
                while (prev->right != nullptr && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    sum_val.push_back(sum_val.back());
                    sum_val.back() += cur->val;
                    current_vec.push_back(cur->val);
                    current_vec_length.push_back(current_vec.size());

                    prev->right = cur;

                    prev_cur = cur;
                    cur = cur->left;
                }
                else
                {
                    if (prev_cur->left == nullptr && sum_val.back() == targetSum)
                    {
                        res.push_back(current_vec);
                    }
                    sum_val.pop_back();
                    current_vec.erase(next(current_vec.begin(), current_vec_length.back()), current_vec.end());
                    sum_val.erase(next(sum_val.begin(), current_vec_length.back() + 1), sum_val.end());
                    current_vec_length.pop_back();
                    prev->right = nullptr;
                    prev_cur = cur;
                    cur = cur->right;
                }
            }
        }
        if (prev_cur->left == nullptr && sum_val.back() == targetSum)
        {
            res.push_back(current_vec);
        }
        return res;
    }
};
// @lc code=end
