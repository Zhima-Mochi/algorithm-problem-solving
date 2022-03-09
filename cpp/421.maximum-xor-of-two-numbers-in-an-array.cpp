/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// @lc code=start
class TreeNode2
{
public:
    TreeNode2() = default;
    TreeNode2 *left;
    TreeNode2 *right;
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        auto root = new TreeNode2();
        for (auto n : nums)
        {
            insertTree(root, n);
        }
        int res = 0;

        int max_val = 0;
        for (int i = 30; i >= 0; i--)
        {
            int tmp = max_val | (1 << i);
            for (auto n : nums)
            {
                if (find(root, (tmp ^ n), i))
                {
                    max_val = tmp;
                    break;
                }
            }
        }
        return max_val;
    }
    void insertTree(TreeNode2 *root, int num)
    {
        auto cur = root;
        for (int i = 30; i != -1; --i)
        {
            if (num & (1 << i))
            {
                if (!cur->right)
                {
                    cur->right = new TreeNode2();
                }
                num &= ~(1 << 31);
                cur = cur->right;
            }
            else
            {
                if (!cur->left)
                {
                    cur->left = new TreeNode2();
                }
                cur = cur->left;
            }
        }
    }
    bool find(TreeNode2 *root, int num, int bound)
    {
        auto cur = root;
        for (int i = 30; i >= bound; --i)
        {
            if (num & (1 << i))
            {
                if (!cur->right)
                {
                    return false;
                }
                num &= ~(1 << i);
                cur = cur->right;
            }
            else
            {
                if (!cur->left)
                {
                    return false;
                }
                cur = cur->left;
            }
        }
        return true;
    }
};
// @lc code=end
