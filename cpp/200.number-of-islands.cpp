/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int island_count = 0;
        int height = grid.size();
        int width = grid[0].size();
        int cur_h = 0, cur_w = 0;
        while (cur_h != height)
        {
            cur_w = 0;
            while (cur_w != width)
            {
                if (grid[cur_h][cur_w] == '1')
                {
                    ++island_count;
                    check_island(grid, height, width, cur_h, cur_w);
                }
                // if (grid[cur_h][cur_w] == 'X')
                // {
                //     grid[cur_h][cur_w] = '1';
                // }
                ++cur_w;
            }
            ++cur_h;
        }
        return island_count;
    }
    void check_island(vector<vector<char>> &grid, int &height, int &width, int cur_h, int cur_w)
    {
        if (cur_h == -1 || cur_w == -1 || cur_h == height || cur_w == width)
        {
            return;
        }
        if (grid[cur_h][cur_w] == '1')
        {
            grid[cur_h][cur_w] = 'X';
            check_island(grid, height, width, cur_h - 1, cur_w);
            check_island(grid, height, width, cur_h + 1, cur_w);
            check_island(grid, height, width, cur_h, cur_w - 1);
            check_island(grid, height, width, cur_h, cur_w + 1);
        }
    }
};
// @lc code=end
//[["1","0","1","1","1"],["1","0","1","0","1"],["1","1","1","0","1"]]
