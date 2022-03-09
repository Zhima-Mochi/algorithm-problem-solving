/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        height = grid.size();
        width = grid[0].size();
        k %= height * width;
        if (k == 0)
        {
            return grid;
        }
        reverse(grid, 0, width * height - 1);
        reverse(grid, k, width * height - 1);
        reverse(grid, 0, k - 1);
        return grid;
    }
    void reverse(vector<vector<int>> &grid, int start, int end)
    {
        while (start < end)
        {
            swap(grid[start / width][start % width], grid[end / width][end % width]);
            ++start;
            --end;
        }
    }
};
// @lc code=end
