/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> island_area;
    int height;
    int width;

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        height = grid.size();
        width = grid[0].size();
        int res = 1;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] == 1)
                {
                    island_area.push_back(0);
                    traversalIsland(grid, i, j);
                    res = max(res, island_area.back());
                }
            }
        }
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] == 0)
                {
                    connectIsland(grid, i, j, res);
                }
            }
        }
        return res;
    }
    void traversalIsland(vector<vector<int>> &grid, int m, int n)
    {
        if (grid[m][n] == 1)
        {
            ++island_area.back();
            grid[m][n] = -1 * island_area.size();
            if (m > 0)
            {
                traversalIsland(grid, m - 1, n);
            }
            if (n > 0)
            {
                traversalIsland(grid, m, n - 1);
            }
            if (m < height - 1)
            {
                traversalIsland(grid, m + 1, n);
            }
            if (n < width - 1)
            {
                traversalIsland(grid, m, n + 1);
            }
        }
        else
        {
            return;
        }
    }
    void connectIsland(vector<vector<int>> &grid, int m, int n, int &res)
    {

        unordered_set<int> area_index;
        if (m > 0)
        {
            if (grid[m - 1][n] < 0)
            {
                area_index.insert(grid[m - 1][n] * -1 - 1);
            }
        }
        if (n > 0)
        {
            if (grid[m][n - 1] < 0)
            {
                area_index.insert(grid[m][n - 1] * -1 - 1);
            }
        }
        if (m < height - 1)
        {
            if (grid[m + 1][n] < 0)
            {
                area_index.insert(grid[m + 1][n] * -1 - 1);
            }
        }
        if (n < width - 1)
        {
            if (grid[m][n + 1] < 0)
            {
                area_index.insert(grid[m][n + 1] * -1 - 1);
            }
        }
        if (area_index.size() < 1)
        {
            return;
        }
        else if (area_index.size() == 1)
        {
            res = max(res, island_area[*area_index.begin()] + 1);
            return;
        }
        int sum_val=1;
        for (auto &ind : area_index)
        {
            sum_val+=island_area[ind];
        }
        res = max(res, sum_val);
    }
};
// @lc code=end
//[[0,0,0,0,0,0,0],[0,1,1,1,1,0,0],[0,1,0,0,1,0,0],[1,0,1,0,1,0,0],[0,1,0,0,1,0,0],[0,1,0,0,1,0,0],[0,1,1,1,1,0,0]]
