/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */
#include <vector>
#include <stack>
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        stack<TreeNode *> node_st;
        stack<int> value_st;
        auto cursor = root;
        int sum_value = 0;
        while (true)
        {
            if (cursor != nullptr)
            {
                node_st.push(cursor);
                sum_value += cursor->val;

                value_st.push(sum_value);
                cursor = cursor->left;
            }
            else if (!node_st.empty())
            {

                
                cursor = node_st.top();
                if (sum_value == targetSum && cursor->left==nullptr && cursor->right==nullptr)
                {
                    return true;
                }
                cursor=cursor->right;
                node_st.pop();
                sum_value = value_st.top();
                value_st.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
