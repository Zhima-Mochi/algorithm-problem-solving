/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */
#include <vector>
#include <queue>
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
    static TreeNode *copy_tree(TreeNode *current_tree_head)
    {
        auto res = new TreeNode(current_tree_head->val);
        vector<TreeNode *> st = {current_tree_head}, new_st = {res};
        auto cur = current_tree_head;
        auto new_tree_cur = res;
        while (true)
        {
            if (cur->left)
            {
                auto new_node = new TreeNode(cur->left->val);
                new_tree_cur->left = new_node;
                cur = cur->left;
                new_tree_cur = new_node;
                st.push_back(cur);
                new_st.push_back(new_node);
            }
            else
            {
                auto find = false;
                while (st.size())
                {
                    cur = st.back();
                    new_tree_cur = new_st.back();
                    st.pop_back();
                    new_st.pop_back();
                    if (cur->right)
                    {
                        auto new_node = new TreeNode(cur->right->val);
                        new_tree_cur->right = new_node;

                        cur = cur->right;
                        new_tree_cur = new_node;

                        st.push_back(cur);
                        new_st.push_back(new_node);

                        find = true;
                        break;
                    }
                }
                if (find == false)
                {
                    break;
                }
            }
        }
        return res;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> res;
        res.push_back(new TreeNode(1));
        auto start = 1;
        while (++start <= n)
        {
            int len = res.size();
            for (int i = 0; i != len; ++i)
            {
                //head
                auto head = new TreeNode(start);
                head->left = copy_tree(res[i]);
                res.push_back(head);
                //middle
                auto cur = res[i];
                auto new_node = new TreeNode(start);
                while (cur->right)
                {
                    auto original_right = cur->right;
                    new_node->left = original_right;
                    cur->right = new_node;
                    res.push_back(copy_tree(res[i]));
                    cur->right = original_right;
                    cur = cur->right;
                }
                //tail(replace original one)
                cur->right = new_node;
                new_node->left = nullptr;
            }
        }
        return res;
    }
};
// @lc code=end

//   void insert_tree(TreeNode *current_tree_head, int value)
//     {
//         auto cur_node = current_tree_head;
//         while (true)
//         {
//             if (value > cur_node->val)
//             {
//                 if (cur_node->right)
//                 {
//                     cur_node = cur_node->right;
//                 }
//                 else
//                 {
//                     cur_node->right = new TreeNode(value);
//                     break;
//                 }
//             }
//             else
//             {
//                 if (cur_node->left)
//                 {
//                     cur_node = cur_node->left;
//                 }
//                 else
//                 {
//                     cur_node->left = new TreeNode(value);
//                     break;
//                 }
//             }
//         }
//     }