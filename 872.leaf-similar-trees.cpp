/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
class LeafIter
{
public:
    LeafIter(TreeNode *_root) : cur(_root) {}
    TreeNode *next()
    {
        while (true)
        {
            if (cur)
            {
                st.push_back(cur);
                cur = cur->left;
            }
            else if (!st.empty())
            {
                cur = st.back()->right;
                auto temp = st.back();
                st.pop_back();
                if (!cur && temp->left == nullptr)
                {
                    return temp;
                }
            }
            else
            {
                return nullptr;
            }
        }
    }

private:
    TreeNode *cur;
    vector<TreeNode *> st;
};
class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        auto leaf_cur_1 = LeafIter(root1);
        auto leaf_cur_2 = LeafIter(root2);
        TreeNode *cur_1, *cur_2;
        while ((cur_1 = leaf_cur_1.next()) && (cur_2 = leaf_cur_2.next()))
        {
            if (cur_1->val != cur_2->val)
            {
                return false;
            }
        }
        return cur_1 == nullptr && leaf_cur_2.next() == nullptr;
    }
};
// @lc code=end
