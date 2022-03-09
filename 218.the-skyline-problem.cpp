/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
class _TreeNode
{
public:
    int left;
    int right;
    int height;
    _TreeNode *left_child = nullptr, *right_child = nullptr;
    _TreeNode(int l, int r, int h)
    {
        left = l, right = r, height = h;
    }
    void insert_node(int l, int r, int h)
    {
        if (h <= height)
        {
            return;
        }
        if (left == l && right == r)
        {
            height = max(height, h);
        }
        if (left != l || right != r || left_child)
        {
            int middle = left + (right - left) / 2;
            if (left_child == nullptr)
            {
                left_child = new _TreeNode(left, middle, height);
                right_child = new _TreeNode(middle + 1, right, height);
            }
            if (r <= middle)
            {
                left_child->insert_node(l, r, h);
            }
            else if (l > middle)
            {
                right_child->insert_node(l, r, h);
            }
            else
            {
                left_child->insert_node(l, middle, h);
                right_child->insert_node(middle + 1, r, h);
            }
        }
        return;
    }
};
class SegmentTree
{
public:
    _TreeNode *root;
    SegmentTree(int left, int right)
    {
        root = new _TreeNode(left, right, 0);
    }
    void insert(int l, int r, int h)
    {
        root->insert_node(l, r, h);
    }
    vector<vector<int>> getSkyline()
    {
        vector<vector<int>> res;
        traverse(res, root);
        return res;
    }
    void traverse(vector<vector<int>> &res, _TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        traverse(res, node->left_child);
        traverse(res, node->right_child);
        if (!node->left_child && !node->right_child)
        {
            if (res.empty())
            {
                res.push_back({node->left, node->height});
            }
            else if (res.back()[1] != node->height)
            {
                res.push_back({node->left, node->height});
            }
        }
    }
};
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        sort(buildings.begin(), buildings.end(), [](vector<int> &l, vector<int> &r)
             { return l[2] > r[2]; });
        int left = INT_MAX, right = 0;
        for (auto &building : buildings)
        {
            left = min(left, building[0]);
            right = max(right, building[1]);
        }
        auto s_t = SegmentTree(left, right);
        for (auto &building : buildings)
        {
            s_t.insert(building[0], building[1] - 1, building[2]);
        }
        return s_t.getSkyline();
    }
};
// @lc code=end
