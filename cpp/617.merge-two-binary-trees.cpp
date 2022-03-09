/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 */
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

//recursion solution
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 && root2)
        {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        return root1 ? root1 : root2;
    }
};
// @lc code=end

//iteration solution
// class Solution
// {
// public:
//     TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
//     {
//         stack<TreeNode *> st1, st2;
//         TreeNode *cur1 = root1, *cur2 = root2, *prev1;
//         if (!cur1 || !cur2)
//         {
//             if (cur1)
//             {
//                 return cur1;
//             }
//             else
//             {
//                 return cur2;
//             }
//         }
//         while (true)
//         {

//             cur1->val += cur2->val;

//             if (cur1->left && cur2->left)
//             {
//                 st1.push(cur1);
//                 st2.push(cur2);
//                 cur1 = cur1->left;
//                 cur2 = cur2->left;
//             }
//             else
//             {
//                 if (cur2->left)
//                 {
//                     cur1->left = cur2->left;
//                 }
//                 while (!st1.empty() && !(cur1->right && cur2->right))
//                 {
//                     if (cur2->right)
//                     {
//                         cur1->right = cur2->right;
//                     }
//                     cur1 = st1.top();
//                     cur2 = st2.top();
//                     st1.pop();
//                     st2.pop();
//                 }
//                 if (!(cur1->right && cur2->right))
//                 {
//                     if (cur2->right)
//                     {
//                         cur1->right = cur2->right;
//                     }
//                     break;
//                 }
//                 cur1 = cur1->right;
//                 cur2 = cur2->right;
//             }
//         }
//         return root1;
//     }
// };