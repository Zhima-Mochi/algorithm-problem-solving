/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<int, vector<int>> tree;
    vector<int> countChild;
    vector<int> accum;
    int len;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        len = n;
        countChild = accum = vector<int>(n);
        for (auto &edge : edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        //subchildAccum
        helpler(0, -1);
        //subchildAccum->allNodeAccum
        helpler2(0, -1);
        return accum;
    }
    void helpler(int current, int prev)
    {
        for (auto child : tree[current])
        {
            if (child == prev)
            {
                continue;
            }
            helpler(child, current);
            countChild[current] += countChild[child];
            accum[current] += accum[child] + countChild[child];
        }
        ++countChild[current];
    }
    void helpler2(int current, int prev)
    {
        for (auto child : tree[current])
        {
            if (child == prev)
            {
                continue;
            }
            accum[child] = accum[current] - countChild[child] + len - countChild[child];
            helpler2(child, current);
        }
    }
};
// @lc code=end
