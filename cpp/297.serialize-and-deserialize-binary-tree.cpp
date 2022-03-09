/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */
#include <string>
#include <sstream>
#include <functional>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
};
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        function<void(TreeNode *)> preOrder = [&](TreeNode *node)
        {
            if (!node)
            {
                res.append("- ");
                return;
            }
            res.append(to_string(node->val));
            res.push_back(' ');
            preOrder(node->left);
            preOrder(node->right);
        };
        preOrder(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
        {
            return nullptr;
        }
        istringstream iss(data);
        TreeNode *dummy = new TreeNode(0);
        auto cur = dummy;
        function<void(TreeNode *)> buildTree = [&](TreeNode *node)
        {
            string s;
            iss >> s;
            if (s != "-")
            {
                node->left = new TreeNode(stoi(s));
                buildTree(node->left);
            }
            if (node == dummy)
            {
                return;
            }
            iss >> s;
            if (s != "-")
            {
                node->right = new TreeNode(stoi(s));
                buildTree(node->right);
            }
        };
        buildTree(dummy);
        return dummy->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
