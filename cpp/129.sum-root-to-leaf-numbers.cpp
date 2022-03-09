/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode *root)
    {
        vector<int> collection_len = {0};
        vector<int> collection_sum = {0};
        auto init_head = new TreeNode(0, root, nullptr);
        TreeNode *cur = init_head;
        int res = 0;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                collection_sum.push_back(collection_sum.back() * 10 + cur->val);
                cur = cur->right;
            }
            else
            {
                auto prev = cur->left;
                while (prev->right != cur && prev->right)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    collection_sum.push_back(collection_sum.back() * 10 + cur->val);
                    collection_len.push_back(collection_sum.size());
                    cur = cur->left;
                }
                else
                {
                    prev->right = nullptr;
                    if (prev->left == nullptr)
                    {
                        res += collection_sum.back();
                    }
                    collection_sum.erase(collection_sum.begin() + collection_len.back(), collection_sum.end());
                    collection_len.pop_back();
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end
