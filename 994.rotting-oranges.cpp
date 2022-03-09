/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int height = grid.size();
        int width = grid[0].size();
        queue<pair<int, int>> rotten_pos;
        int fresh_num = 0;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++fresh_num;
                }
                else if (grid[i][j] == 2)
                {
                    rotten_pos.push({i, j});
                }
            }
        }
        int time_count = 0;
        while (fresh_num && !rotten_pos.empty())
        {
            ++time_count;
            int q_len = rotten_pos.size();
            while (q_len--)
            {
                int row = rotten_pos.front().first;
                int col = rotten_pos.front().second;
                rotten_pos.pop();
                for (auto &d : direction)
                {
                    int next_row = row + d[0];
                    int next_col = col + d[1];
                    if (next_row >= 0 && next_row <= height - 1 && next_col >= 0 && next_col <= width - 1)
                    {
                        if (grid[next_row][next_col] == 1)
                        {
                            --fresh_num;
                            grid[next_row][next_col] = 2;
                            rotten_pos.push({next_row, next_col});
                        }
                    }
                }
            }
        }
        if (fresh_num)
        {
            return -1;
        }
        else
        {
            return time_count;
        }
    }
};
// @lc code=end
