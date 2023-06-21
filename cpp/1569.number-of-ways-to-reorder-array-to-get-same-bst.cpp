/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Node
{
public:
    int val;
    int count;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr), count(1) {}
};
class Tree
{

public:
    Tree(int x) : root(new Node(x)) {}
    Node *root;
    void insert(int x)
    {
        auto node = new Node(x);
        auto cur = root;
        while (cur)
        {
            cur->count++;
            if (x < cur->val)
            {
                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = node;
                    break;
                }
            }
            else
            {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = node;
                    break;
                }
            }
        }
    }
};
int mod = 1000000007;
class Solution
{
public:
    vector<vector<int>> c;
    int numOfWays(vector<int> &nums)
    {
        auto tree = new Tree(nums[0]);
        int w = nums.size();
        for (int i = 1; i < w; i++)
        {
            tree->insert(nums[i]);
        }
        c = vector<vector<int>>(w + 1, vector<int>(w + 1, 0));
        for (int i = 0; i <= w; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    c[i][j] = 1;
                }
                else
                {
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
                }
            }
        }
        return dfs(tree->root) - 1;
    }
    int dfs(Node *node)
    {
        if (!node)
        {
            return 1;
        }
        auto left_count = node->left ? node->left->count : 0;
        auto right_count = node->right ? node->right->count : 0;
        long long left = dfs(node->left);
        long long right = dfs(node->right);
        return (c[left_count + right_count][left_count] * left % mod * right % mod) % mod;
    }
};
// @lc code=end
