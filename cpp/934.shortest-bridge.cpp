/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;
// @lc code=start
// t:O((R*C)^2), s:O(R*C)
class Solution
{
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int w;
    int h;
    unordered_set<int> island_1, island_2;

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        h = grid.size();
        w = grid[0].size();
        int color = 2;
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (grid[i][j] == 1)
                {
                    flip(grid, i, j, 1, color++);
                }
                if (grid[i][j] == 2 && is_edge(grid, i, j))
                {
                    island_1.insert((i << 10) + j);
                }
                else if (grid[i][j] == 3 && is_edge(grid, i, j))
                {
                    island_2.insert((i << 10) + j);
                }
            }
        }
        int res = INT_MAX;
        for (auto &p1 : island_1)
        {
            for (auto &p2 : island_2)
            {
                int r_diff = abs((p1 >> 10) - (p2 >> 10));
                int c_diff = abs((p1 & 0xFF) - (p2 & 0xFF));
                res = min(res, r_diff + c_diff - 1);
            }
        }
        return res;
    }
    bool is_edge(vector<vector<int>> &grid, int r, int c)
    {
        for (auto &d : directions)
        {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w)
            {
                if (grid[nr][nc] == 0)
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void flip(vector<vector<int>> &grid, int r, int c, int og_num, int num)
    {
        if (grid[r][c] == og_num)
        {
            grid[r][c] = num;
            for (auto &d : directions)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w)
                {
                    flip(grid, nr, nc, og_num, num);
                }
            }
        }
    }
};
// @lc code=end

// t:O(R*C), s:O(R*C)
// class Solution
// {
//     vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     int w;
//     int h;

// public:
//     int shortestBridge(vector<vector<int>> &grid)
//     {
//         h = grid.size();
//         w = grid[0].size();
//         int color = 2;
//         for (int i = 0; i != h; ++i)
//         {
//             for (int j = 0; j != w; ++j)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     flip(grid, i, j, 1, color);
//                     ++color;
//                 }
//             }
//         }
//         vector<vector<pair<int, int>>> dp(h, vector<pair<int, int>>(w, {1000, 1000}));
//         for (int i = 0; i != h; ++i)
//         {
//             for (int j = 0; j != w; ++j)
//             {
//                 if (grid[i][j] == 2)
//                 {
//                     dp[i][j].first = 0;
//                 }
//                 else if (grid[i][j] == 3)
//                 {
//                     dp[i][j].second = 0;
//                 }
//                 else
//                 {
//                     if (i > 0)
//                     {
//                         dp[i][j].first = min(dp[i][j].first, dp[i - 1][j].first + 1);
//                         dp[i][j].second = min(dp[i][j].second, dp[i - 1][j].second + 1);
//                     }
//                     if (j > 0)
//                     {
//                         dp[i][j].first = min(dp[i][j].first, dp[i][j - 1].first + 1);
//                         dp[i][j].second = min(dp[i][j].second, dp[i][j - 1].second + 1);
//                     }
//                 }
//             }
//         }
//         int res = INT_MAX;
//         for (int i = h - 1; i != -1; --i)
//         {
//             for (int j = w - 1; j != -1; --j)
//             {
//                 if (grid[i][j] != 0)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     if (i < h - 1)
//                     {
//                         dp[i][j].first = min(dp[i][j].first, dp[i + 1][j].first + 1);
//                         dp[i][j].second = min(dp[i][j].second, dp[i + 1][j].second + 1);
//                     }
//                     if (j < w - 1)
//                     {
//                         dp[i][j].first = min(dp[i][j].first, dp[i][j + 1].first + 1);
//                         dp[i][j].second = min(dp[i][j].second, dp[i][j + 1].second + 1);
//                     }
//                     res = min(res, dp[i][j].first + dp[i][j].second - 1);
//                 }
//             }
//         }
//         return res;
//     }
//     void flip(vector<vector<int>> &grid, int r, int c, int og_num, int num)
//     {
//         if (grid[r][c] == og_num)
//         {
//             grid[r][c] = num;
//             for (auto &d : directions)
//             {
//                 int nr = r + d[0];
//                 int nc = c + d[1];
//                 if (nr >= 0 && nr < h && nc >= 0 && nc < w)
//                 {
//                     flip(grid, nr, nc, og_num, num);
//                 }
//             }
//         }
//     }
// };