/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//O(n log n) O(n)
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        TreeNode *pre_root = new TreeNode();
        pre_root->left = generate(head, nullptr);
        return pre_root->left;
    }
    TreeNode *generate(ListNode *beg, ListNode *ed)
    {
        if (beg == ed)
        {
            return nullptr;
        }
        auto slow = beg, fast = beg;
        while (fast->next != ed && fast->next->next != ed)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != ed)
        {
            slow = slow->next;
        }
        auto res = new TreeNode(slow->val);
        res->left = generate(beg, slow);
        res->right = generate(slow->next, ed);
        return res;
    }
};
// @lc code=end
//[1,2,3,4,5,6,7,8,9,10,11]