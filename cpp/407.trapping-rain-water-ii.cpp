/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    int res = 0;
    int width, height;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        auto rainHeightMap = heightMap;
        height = heightMap.size();
        width = heightMap[0].size();
        for (int i = 1; i < height - 1; ++i)
        {
            auto &row_elem = heightMap[i];
            int left = 0, right = width - 1;
            int max_left = 0, max_right = 0;
            while (left < right)
            {
                if (row_elem[left] <= row_elem[right])
                {
                    if (row_elem[left] <= max_left)
                    {
                        res += max_left - row_elem[left];
                        rainHeightMap[i][left] = max_left;
                    }
                    else
                    {
                        max_left = row_elem[left];
                    }
                    ++left;
                }
                else
                {
                    if (row_elem[right] <= max_right)
                    {
                        res += max_right - row_elem[right];
                        rainHeightMap[i][right] = max_right;
                    }
                    else
                    {
                        max_right = row_elem[right];
                    }
                    --right;
                }
            }
        }
        auto comp = [&heightMap](pair<int, int> &l, pair<int, int> &r)
        { return heightMap[l.first][l.second] > heightMap[r.first][r.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            height_order(comp);
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                height_order.push({i, j});
            }
        }
        while (!height_order.empty())
        {
            auto pos = height_order.top();
            height_order.pop();
            diminish_water(heightMap, rainHeightMap, pos.first, pos.second, rainHeightMap[pos.first][pos.second]);
        }
        return res;
    }
    void diminish_water(vector<vector<int>> &heightMap, vector<vector<int>> &rainHeightMap, int i, int j, int min_height)
    {
        if (rainHeightMap[i][j] > min_height)
        {
            if (min_height >= heightMap[i][j])
            {
                res -= rainHeightMap[i][j] - min_height;
                rainHeightMap[i][j] = min_height;
            }
            else
            {
                res -= rainHeightMap[i][j] - heightMap[i][j];
                rainHeightMap[i][j] = heightMap[i][j];
            }
        }
        if (rainHeightMap[i][j] == min_height)
        {
            for (auto &d : directions)
            {
                int nr = i + d[0];
                int nc = j + d[1];
                if (nr <= 0 || nc <= 0 || nr >= height - 1 || nc >= width - 1)
                {
                    continue;
                }
                if (rainHeightMap[nr][nc] > min_height && heightMap[nr][nc] != rainHeightMap[nr][nc])
                {
                    diminish_water(heightMap, rainHeightMap, nr, nc, min_height);
                }
            }
        }
    }
};
// @lc code=end