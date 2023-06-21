/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n*m*log(n*m)) s:O(n*m)
int mod = 1000000007;
class Solution
{
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int countPaths(vector<vector<int>> &grid)
    {
        auto comp = [&](pair<int, int> &l, pair<int, int> &r)
        {
            int a = grid[l.first][l.second];
            int b = grid[r.first][r.second];
            return a > b;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> is_strict_positioins(comp);
        int l = grid.size(), w = grid[0].size();
        long long res =0;
        vector<vector<int>> record(l, vector<int>(w, 1));
        for (int i = 0; i != l; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                is_strict_positioins.push({i, j});
            }
        }
        while (!is_strict_positioins.empty())
        {
            auto [i, j] = is_strict_positioins.top();
            is_strict_positioins.pop();
            for (auto &direction : directions)
            {
                int x = i + direction[0], y = j + direction[1];
                if (x < 0 || x >= l || y < 0 || y >= w)
                {
                    continue;
                }
                if (grid[x][y] > grid[i][j])
                {
                    record[x][y] += record[i][j];
                    record[x][y] %= mod;
                }
            }
            res += record[i][j];
            res %= mod;
        }
        return res;
    }
};
// @lc code=end
