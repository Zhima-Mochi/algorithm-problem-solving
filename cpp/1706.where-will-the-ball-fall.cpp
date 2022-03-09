/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        vector<int> res(w, -1);
        for (int i = 0; i != w; ++i)
        {
            int col = i;
            bool flag = true;
            for (int j = 0; j != h; ++j)
            {
                int shift = grid[j][col];
                col += shift;
                if (col < 0 || col == w || grid[j][col] != shift)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res[i] = col;
            }
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     vector<int> findBall(vector<vector<int>> &grid)
//     {
//         int h = grid.size();
//         int w = grid[0].size();
//         vector<int> record(w);
//         iota(record.begin(), record.end(), 0);
//         for (int i = 0; i != h; ++i)
//         {
//             vector<int> next_record(w, -1);
//             if (w > 1 && grid[i][0] == 1 && grid[i][1] == 1)
//             {
//                 next_record[1] = record[0];
//             }
//             if (w > 1 && grid[i][w - 1] == -1 && grid[i][w - 2] == -1)
//             {
//                 next_record[w - 2] = record[w - 1];
//             }
//             for (int j = 1; j < w - 1; ++j)
//             {
//                 if (grid[i][j] == 1 && grid[i][j + 1] == 1)
//                 {
//                     next_record[j + 1] = record[j];
//                 }
//                 else if (grid[i][j] == -1 && grid[i][j - 1] == -1)
//                 {
//                     next_record[j - 1] = record[j];
//                 }
//             }
//             record = move(next_record);
//         }
//         vector<int> res(w, -1);
//         for (int i = 0; i != w; ++i)
//         {
//             if (record[i] != -1)
//             {
//                 res[record[i]] = i;
//             }
//         }
//         return res;
//     }
// };
