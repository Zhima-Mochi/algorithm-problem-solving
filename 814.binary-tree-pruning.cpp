/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
    TreeNode *pruneTree(TreeNode *root)
    {
        auto pre_root = new TreeNode(0, root, nullptr);
        TreeNode *cur = pre_root, *prev = nullptr;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                cur = cur->right;
            }
            else
            {
                prev = cur->left;
                while (prev->right != nullptr && prev->right != cur)
                {
                    prev = prev->right;
                }

                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    reverseDelete(&(cur->left), &prev);
                    prev->right = nullptr;
                    auto temp = cur->left;
                    if (temp->val == 0 && temp->right == nullptr && temp->left == nullptr)
                    {
                        cur->left = nullptr;
                        if (temp != root)
                        {
                            delete (temp);
                        }
                    }
                    cur = cur->right;
                }
            }
        }
        return pre_root->left;
    }

    void reverse(TreeNode **from, TreeNode **to)
    {
        if (*from == *to)
            return;
        TreeNode *x = *from, *y = (*from)->right, *z;
        while (true)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if (x == *to)
                break;
        }
    }
    void reverseDelete(TreeNode **from, TreeNode **to)
    {
        reverse(from, to);
        TreeNode *p = *to;
        while (true)
        {
            if (p == *from || p != *to)
                break;
            auto next_cur = p->right;
            if (p->val == 0 && p->left == nullptr)
            {
                p->right = nullptr;
                *to = next_cur;
                delete (p);
            }
            p = next_cur;
        }
        reverse(to, from);
    }
};

// @lc code=end
