/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 */
#include <set>
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

//Bad solution, should use two point of tree cursor
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        set<int> oset;
        return preOrder(root, oset, k);
    }
    bool preOrder(TreeNode *root, set<int> &record, int &k)
    {
        if (!root)
        {
            return false;
        }
        if (record.count(k - root->val))
        {
            return true;
        }
        else
        {
            record.insert(root->val);
            return preOrder(root->left, record, k) || preOrder(root->right, record, k);
        }
    }
};
// @lc code=end
// class Solution
// {
//     TreeNode *origin;

// public:
//     bool findTarget(TreeNode *root, int k)
//     {
//         origin = root;
//         return preOrder(root, k);
//     }
//     bool search(TreeNode *root, TreeNode *counter, int val)
//     {
//         if (!root)
//         {
//             return false;
//         }
//         if (root->val == val)
//         {
//             if (root != counter)
//             {

//                 return true;
//             }
//             else
//             {
//                 return search(root->left, counter, val) || search(root->right, counter, val);
//             }
//         }
//         return root->val > val ? search(root->left, counter, val) : search(root->right, counter, val);
//     }
//     bool preOrder(TreeNode *root, int &k)
//     {
//         if (!root)
//         {
//             return false;
//         }
//         if (search(origin, root, k - root->val))
//         {
//             return true;
//         }
//         else
//         {
//             return preOrder(root->left, k) || preOrder(root->right, k);
//         }
//     }
// };