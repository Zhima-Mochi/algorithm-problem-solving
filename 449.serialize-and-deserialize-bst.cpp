/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */
#include <string>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        auto cur = root;
        vector<TreeNode *> st;
        string res;
        while (true)
        {
            if (cur)
            {
                st.push_back(cur);
                res.push_back(cur->val >> 8);
                res.push_back((cur->val & 0xFF) - 128);
                cur = cur->left;
            }
            else if (!st.empty())
            {
                res.push_back(-128);
                cur = st.back()->right;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int len = data.size();
        int pos = 0;
        TreeNode *dummy = new TreeNode(0);
        vector<TreeNode *> st;
        auto cur = dummy;
        bool inLeft = true;
        while (pos != len)
        {
            if (data[pos] == -128)
            {
                cur = st.back();
                st.pop_back();
                inLeft = false;
                ++pos;
            }
            else
            {
                if (inLeft)
                {
                    cur->left = new TreeNode((data[pos] << 8) + data[pos + 1] + 128);
                    cur = cur->left;
                }
                else
                {
                    cur->right = new TreeNode((data[pos] << 8) + data[pos + 1] + 128);
                    inLeft = true;
                    cur = cur->right;
                }
                st.push_back(cur);
                pos += 2;
            }
        }
        return dummy->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
