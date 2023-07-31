/*
 * @lc app=leetcode id=2569 lang=cpp
 *
 * [2569] Handling Sum Queries After Update
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Node
{
public:
    int l, r;
    long long sum;
    bool tag;
};

class SegmentTree
{
    vector<Node> tree;

public:
    SegmentTree(vector<int> &nums)
    {
        int w = nums.size();
        tree = vector<Node>(4 * w);
        build(nums, 0, w - 1, 0);
    }
    void build(vector<int> &nums, int l, int r, int idx)
    {
        tree[idx].l = l;
        tree[idx].r = r;
        tree[idx].tag = false;
        if (l == r)
        {
            tree[idx].sum = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(nums, l, mid, 2 * idx + 1);
        build(nums, mid + 1, r, 2 * idx + 2);
        tree[idx].sum = tree[2 * idx + 1].sum + tree[2 * idx + 2].sum;
    }
    void flip(int l, int r, int idx)
    {
        if (tree[idx].l >= l && tree[idx].r <= r)
        {
            tree[idx].sum = (tree[idx].r - tree[idx].l + 1) - tree[idx].sum;
            tree[idx].tag = !tree[idx].tag;
            return;
        }
        pushdown(idx);

        int mid = l + (r - l) / 2;
        if (tree[2 * idx + 1].r >= l)
        {
            flip(l, r, 2 * idx + 1);
        }
        if (tree[2 * idx + 2].l <= r)
        {
            flip(l, r, 2 * idx + 2);
        }
        tree[idx].sum = tree[2 * idx + 1].sum + tree[2 * idx + 2].sum;
    }

    void pushdown(int idx)
    {
        if (tree[idx].tag)
        {
            tree[2 * idx + 1].tag = !tree[2 * idx + 1].tag;
            tree[2 * idx + 1].sum = tree[2 * idx + 1].r - tree[2 * idx + 1].l + 1 - tree[2 * idx + 1].sum;

            tree[2 * idx + 2].tag = !tree[2 * idx + 2].tag;
            tree[2 * idx + 2].sum = tree[2 * idx + 2].r - tree[2 * idx + 2].l + 1 - tree[2 * idx + 2].sum;

            tree[idx].tag = false;
        }
    }

    long long getSum()
    {
        return tree[0].sum;
    }
};

class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        vector<long long> res;
        long long sum = 0;
        for (auto n : nums2)
        {
            sum += n;
        }
        auto segment_tree = SegmentTree(nums1);
        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                segment_tree.flip(q[1], q[2], 0);
            }
            else if (q[0] == 2)
            {
                sum += segment_tree.getSum() * q[1];
            }
            else
            {
                res.push_back(sum);
            }
        }
        return res;
    }
};
// @lc code=end
