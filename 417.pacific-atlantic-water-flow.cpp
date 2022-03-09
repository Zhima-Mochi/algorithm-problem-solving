/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        height = heights.size();
        width = heights[0].size();
        vector<vector<int>> dp(height, vector<int>(width));
        dfs(heights, dp, 0, width - 1, 3);
        dfs(heights, dp, height - 1, 0, 3);

        for (int j = 0; j < width; ++j)
        {
            dfs(heights, dp, 0, j, 1);
            dfs(heights, dp, height - 1, j, 2);
        }
        for (int i = 0; i < height; ++i)
        {
            dfs(heights, dp, i, 0, 1);
            dfs(heights, dp, i, width - 1, 2);
        }
        vector<vector<int>> res;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (dp[i][j] == 3)
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &dp, int row, int col, const int &ocean)
    {
        if ((dp[row][col] & ocean) == ocean)
        {
            return;
        }
        else
        {
            dp[row][col] |= ocean;
        }
        if (row > 0 && heights[row][col] <= heights[row - 1][col])
        {
            dfs(heights, dp, row - 1, col, ocean);
        }
        if (row < height - 1 && heights[row][col] <= heights[row + 1][col])
        {
            dfs(heights, dp, row + 1, col, ocean);
        }
        if (col > 0 && heights[row][col] <= heights[row][col - 1])
        {
            dfs(heights, dp, row, col - 1, ocean);
        }
        if (col < width - 1 && heights[row][col] <= heights[row][col + 1])
        {
            dfs(heights, dp, row, col + 1, ocean);
        }
    }
};
// @lc code=end
