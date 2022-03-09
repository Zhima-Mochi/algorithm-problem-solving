/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int h = isWater.size();
        int w = isWater[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (isWater[i][j] == 0)
                {
                    isWater[i][j] = INT_MAX;
                }
                else
                {
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int mon_height = 1;
        while (!q.empty())
        {
            int q_len = q.size();
            while (q_len--)
            {
                auto row = q.front().first;
                auto col = q.front().second;
                q.pop();
                for (auto &d : directions)
                {
                    auto next_row = row + d[0];
                    auto next_col = col + d[1];
                    if (next_row < 0 || next_row >= h || next_col < 0 || next_col >= w || isWater[next_row][next_col] != INT_MAX)
                    {
                        continue;
                    }
                    isWater[next_row][next_col] = mon_height;
                    q.push({next_row, next_col});
                }
            }
            ++mon_height;
        }
        return isWater;
    }
};
// @lc code=end
