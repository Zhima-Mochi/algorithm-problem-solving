/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int height;
    int width;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        height = grid.size();
        width = grid[0].size();
        int res = 0;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] == 1)
                {
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }
    int bfs(vector<vector<int>> &grid, int row, int col)
    {
        int area = 1;
        grid[row][col] = -1;
        queue<pair<int, int>> island_pos;
        island_pos.push({row, col});
        while (!island_pos.empty())
        {
            int q_len = island_pos.size();
            while (q_len--)
            {
                auto cur_pos = island_pos.front();
                island_pos.pop();
                for (auto &d : direction)
                {
                    int new_row = cur_pos.first + d[0];
                    int new_col = cur_pos.second + d[1];
                    if (new_row >= 0 && new_row <= height - 1 && new_col >= 0 && new_col <= width - 1)
                    {
                        if (grid[new_row][new_col] == 1)
                        {
                            area += 1;
                            grid[new_row][new_col] = -1;
                            island_pos.push({new_row, new_col});
                        }
                    }
                }
            }
        }
        return area;
    }
};
// @lc code=end
