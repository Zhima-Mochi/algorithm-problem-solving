/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
 */
#include <stack>
#include <string>
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
    string tree2str(TreeNode *root)
    {
        string res;
        preOrder(root, res);
        res.pop_back();
        res.pop_back();
        return res;
    }
    void preOrder(TreeNode *root, string &res)
    {
        if (!root)
        {
            if (res.substr(res.size() - 2, 2) == ")(")
            {
                res.pop_back();
                if (res.substr(res.size() - 2, 2) == "()")
                {
                    res.pop_back();
                    res.pop_back();
                }
            }
            else
            {
                res.push_back(')');
                res.push_back('(');
            }
            return;
        }
        res.append(to_string(root->val));
        res.push_back('(');
        preOrder(root->left, res);
        preOrder(root->right, res);

        if (res.size() > 2 && res.substr(res.size() - 2, 2) == ")(")
        {
            res.pop_back();
        }
        res.push_back(')');
        res.push_back('(');
    }
};
// @lc code=end [1,null,2,null,3,null,4]

