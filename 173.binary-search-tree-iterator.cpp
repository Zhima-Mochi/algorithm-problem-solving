/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
        : cur(root)
    {
    }

    int next()
    {
        bool is_find = false;
        int val;
        while (cur && !is_find)
        {
            if (cur->left == nullptr)
            {
                val = cur->val;
                is_find = true;
                cur = cur->right;
            }
            else
            {
                auto prev = cur->left;
                while (prev->right && prev->right != cur)
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

                    val = cur->val;
                    is_find = true;
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return val;
    }

    bool hasNext()
    {
        return cur;
    }

private:
    TreeNode *cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
