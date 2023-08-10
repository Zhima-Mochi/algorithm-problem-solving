/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n^2), s:O(1)
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        vector<int> v;
        for (int i = 0; i != w; ++i)
        {
            if (v.size() < 2)
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(i);
                sort(v.begin(), v.end(), [&](int l, int r)
                     { return grid[0][l] < grid[0][r]; });
                v.pop_back();
            }
        }
        for (int i = 1; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (j != v[0])
                {
                    grid[i][j] += grid[i - 1][v[0]];
                }
                else
                {
                    grid[i][j] += grid[i - 1][v[1]];
                }
            }
            v.clear();
            for (int j = 0; j != w; ++j)
            {
                if (v.size() < 2)
                {
                    v.push_back(j);
                }
                else
                {
                    v.push_back(j);
                    sort(v.begin(), v.end(), [&](int l, int r)
                         { return grid[i][l] < grid[i][r]; });
                    v.pop_back();
                }
            }
        }
        return grid[h - 1][v[0]];
    }
};
// @lc code=end
