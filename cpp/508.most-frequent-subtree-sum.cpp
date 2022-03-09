/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
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
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        int max_freq = 0;
        unordered_map<int, int> umap;
        postOrder(root, umap, max_freq);
        vector<int> res;
        for (auto &p : umap)
        {
            if (p.second == max_freq)
            {
                res.push_back(p.first);
            }
        }
        return res;
    }
    void postOrder(TreeNode *root, unordered_map<int, int> &umap, int &max_freq)
    {
        if (!root)
        {
            return;
        }
        postOrder(root->left, umap, max_freq);
        postOrder(root->right, umap, max_freq);
        root->val += (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        ++umap[root->val];
        max_freq = max(max_freq, umap[root->val]);
    }
};
// @lc code=end
