/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int res = 0;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int height, width;

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        height = grid.size();
        width = grid[0].size();
        int start_row, start_col;
        int blank_num = 0;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ++blank_num;
                }
                else if (grid[i][j] == 1)
                {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        dfs(grid, start_row, start_col, blank_num + 1);
        return res;
    }
    void dfs(vector<vector<int>> &grid, int row, int col, int blank_num)
    {
        if (grid[row][col] == 2)
        {
            if (blank_num == 0)
            {
                ++res;
            }
            return;
        }
        grid[row][col] = -1;
        for (auto &d : directions)
        {
            int nr = row + d[0];
            int nc = col + d[1];
            if (nr < 0 || nr >= height || nc < 0 || nc >= width || grid[nr][nc] == -1)
            {
                continue;
            }
            else
            {
                dfs(grid, nr, nc, blank_num - 1);
            }
        }
        grid[row][col] = 0;
    }
};
// @lc code=end

// // t:O(4^(m*n)), s:O(m*n)
// class Solution
// {
//     vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// public:
//     int uniquePathsIII(vector<vector<int>> &grid)
//     {
//         unordered_map<string, int> memo;
//         int h = grid.size(), w = grid[0].size();
//         int left = 1;
//         for (int i = 0; i != h; ++i)
//         {
//             for (int j = 0; j != w; ++j)
//             {
//                 if (grid[i][j] == 0)
//                 {
//                     left++;
//                 }
//             }
//         }
//         function<int(int, int)> dfs = [&](int row, int col) -> int
//         {
//             if (grid[row][col] == -1)
//             {
//                 return 0;
//             }
//             if (grid[row][col] == 2)
//             {
//                 if (left == 0)
//                 {
//                     return 1;
//                 }
//                 else
//                 {
//                     return 0;
//                 }
//             }
//             grid[row][col] = 1;
//             string grid_str = grid_to_str(grid);
//             if (memo.count(grid_str))
//             {
//                 grid[row][col] = 0;
//                 return memo[grid_str];
//             }
//             grid[row][col] = -1;
//             left -= 1;
//             int res = 0;
//             for (auto &dir : directions)
//             {
//                 int next_row = row + dir[0];
//                 int next_col = col + dir[1];
//                 if (next_row < 0 || next_col < 0 || next_row >= h || next_col >= w)
//                 {
//                     continue;
//                 }
//                 res += dfs(next_row, next_col);
//             }
//             grid[row][col] = 0;
//             left += 1;
//             memo[grid_str] = res;
//             return res;
//         };
//         for (int i = 0; i != h; ++i)
//         {
//             for (int j = 0; j != w; ++j)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     return dfs(i, j);
//                 }
//             }
//         }
//         return 0;
//     }
//     string grid_to_str(vector<vector<int>> &grid)
//     {
//         string res;
//         for (auto &row : grid)
//         {
//             for (auto val : row)
//             {
//                 res.append(to_string(val));
//             }
//         }
//         return res;
//     }
// };