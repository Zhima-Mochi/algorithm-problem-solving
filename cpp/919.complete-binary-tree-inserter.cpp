/*
 * @lc app=leetcode id=919 lang=cpp
 *
 * [919] Complete Binary Tree Inserter
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
#include <queue>
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
// t:O(N), s:O(2^depth)
class CBTInserter
{
    TreeNode *rt;
    queue<TreeNode *> nodes;

public:
    CBTInserter(TreeNode *root)
    {
        rt = root;

        int left_level = 0;
        auto cur = root;
        while (cur->left)
        {
            ++left_level;
            cur = cur->left;
        }

        int right_level = 0;
        cur = root;
        while (cur->right)
        {
            ++right_level;
            cur = cur->right;
        }
        int level = min(left_level, right_level);
        // trasversal
        cur = root;
        vector<pair<TreeNode *, int>> st;
        queue<TreeNode *> children_nodes;
        int depth = 0;
        while (true)
        {
            if (cur)
            {
                if (depth == level)
                {
                    if (!cur->left || !cur->right)
                    {
                        nodes.push(cur);
                    }
                }
                else if (depth > level)
                {
                    children_nodes.push(cur);
                }
                st.push_back({cur, depth});
                cur = cur->left;
                ++depth;
            }
            else if (!st.empty())
            {
                cur = st.back().first->right;
                depth = st.back().second + 1;
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        while (!children_nodes.empty())
        {
            nodes.push(children_nodes.front());
            children_nodes.pop();
        }
    }

    int insert(int val)
    {
        int p_val = nodes.front()->val;
        if (!nodes.front()->left)
        {
            nodes.front()->left = new TreeNode(val);
            nodes.push(nodes.front()->left);
        }
        else
        {
            nodes.front()->right = new TreeNode(val);
            nodes.push(nodes.front()->right);
            nodes.pop();
        }
        return p_val;
    }

    TreeNode *get_root()
    {
        return rt;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
