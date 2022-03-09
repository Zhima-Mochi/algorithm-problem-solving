/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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

// t:O(N+M), s:O(N+M)
class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<TreeNode *> st1, st2;
        auto cur1 = root1, cur2 = root2;
        vector<int> res;
        while (cur1 || cur2 || !st1.empty() || !st2.empty())
        {
            if (cur1)
            {
                st1.push_back(cur1);
                cur1 = cur1->left;
            }
            else if (cur2)
            {
                st2.push_back(cur2);
                cur2 = cur2->left;
            }
            else if (!st1.empty() && !st2.empty())
            {
                if (st1.back()->val <= st2.back()->val)
                {
                    res.push_back(st1.back()->val);
                    cur1 = st1.back()->right;
                    st1.pop_back();
                }
                else
                {
                    res.push_back(st2.back()->val);
                    cur2 = st2.back()->right;
                    st2.pop_back();
                }
            }
            else if (!st1.empty())
            {
                res.push_back(st1.back()->val);
                cur1 = st1.back()->right;
                st1.pop_back();
            }
            else
            {
                res.push_back(st2.back()->val);
                cur2 = st2.back()->right;
                st2.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end
