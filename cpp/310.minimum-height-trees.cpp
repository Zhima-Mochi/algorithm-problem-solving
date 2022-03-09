/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }
        else if (n == 2)
        {
            return {0, 1};
        }

        vector<unordered_set<int>> connected_pts(n);
        for (auto &&edge : edges)
        {
            connected_pts[edge[0]].insert(edge[1]);
            connected_pts[edge[1]].insert(edge[0]);
        }
        vector<int> leaves;
        for (int i = 0; i != n; ++i)
        {
            if (connected_pts[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }
        while (true)
        {
            vector<int> next_leaves;
            for (auto n : leaves)
            {
                if (connected_pts[n].empty())
                {
                    continue;
                }
                int neighbor = *connected_pts[n].begin();
                connected_pts[neighbor].erase(n);
                if (connected_pts[neighbor].size() == 1)
                {
                    next_leaves.push_back(neighbor);
                }
            }
            if (next_leaves.empty())
            {
                break;
            }
            else
            {
                leaves = next_leaves;
            }
        }
        return leaves;
    }
};
// @lc code=end
