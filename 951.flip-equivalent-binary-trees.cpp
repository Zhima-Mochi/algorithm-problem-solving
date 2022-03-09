/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
// t:O(min(n1, n2)), s:O(min(n1, n2))
class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        vector<pair<TreeNode *, TreeNode *>> st;
        auto cur1 = root1, cur2 = root2;
        while (true)
        {
            if (cur1 && cur2)
            {
                if (cur1->val != cur2->val)
                {
                    return false;
                }
                if (cur1->left && cur2->left)
                {
                    if (cur1->left->val != cur2->left->val)
                    {
                        swap(cur2->left, cur2->right);
                    }
                }
                else if (cur1->left || cur2->left)
                {
                    swap(cur2->left, cur2->right);
                }
                st.push_back({cur1, cur2});
                cur1 = cur1->left;
                cur2 = cur2->left;
            }
            else if (cur1 || cur2)
            {
                return false;
            }
            else if (!st.empty())
            {
                cur1 = st.back().first->right;
                cur2 = st.back().second->right;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        return true;
    }
};
// @lc code=end
