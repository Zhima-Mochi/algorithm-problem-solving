/*
 * @lc app=leetcode id=2265 lang=cpp
 *
 * [2265] Count Nodes Equal to Average of Subtree
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
#include <functional>
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
// t:O(n), s:O(n)
class Solution
{
public:
    struct Res
    {
    public:
        int sum;
        int cnt;
        Res(int sum, int cnt) : sum(sum), cnt(cnt) {}
        Res &operator+=(const Res &other)
        {
            sum += other.sum;
            cnt += other.cnt;
            return *this;
        }
    };
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        function<Solution::Res(TreeNode *)> dfs = [&](TreeNode *node) -> Solution::Res
        {
            if (node == nullptr)
            {
                return Res(0, 0);
            }
            Res res = Res(node->val, 1);
            res += dfs(node->left);
            res += dfs(node->right);
            if (node->val == res.sum / res.cnt)
            {
                ans += 1;
            }
            return res;
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end
