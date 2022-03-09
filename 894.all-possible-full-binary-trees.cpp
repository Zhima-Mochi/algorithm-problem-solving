/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
#include <vector>
#include <unordered_map>
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
    unordered_map<int, vector<TreeNode *>> record;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (record.count(n))
        {
            return record[n];
        }
        if (n % 2 == 0)
        {
            return {};
        }
        else if (n == 1)
        {
            return {new TreeNode(0)};
        }
        vector<TreeNode *> res;
        for (int i = 1; i != n; i += 2)
        {
            auto left_parts = allPossibleFBT(i);
            auto right_parts = allPossibleFBT(n - 1 - i);
            for (auto l : left_parts)
            {
                for (auto r : right_parts)
                {
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        record[n] = res;
        return res;
    }
};
// @lc code=end
