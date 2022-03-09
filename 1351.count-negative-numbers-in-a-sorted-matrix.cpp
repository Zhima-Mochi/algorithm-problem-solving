/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int height = grid.size();
        int tail = grid[0].size() - 1;
        int res = 0;
        for (int i = 0; i != height; ++i)
        {
            while (tail != -1 && grid[i][tail] < 0)
            {
                res += (height - i);
                --tail;
            }
            if (tail == -1)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int countNegatives(vector<vector<int>> &grid)
//     {
//         int height = grid.size();
//         int width = grid[0].size();
//         int negative_count = 0;
//         int res = 0;
//         for (int i = 0; i != height; ++i)
//         {
//             auto next_negative_count = upper_bound(grid[i].rbegin() + negative_count, grid[i].rend(), -1) - grid[i].rbegin();
//             res += (next_negative_count - negative_count) * (height - i);
//             negative_count = move(next_negative_count);
//             if (negative_count == width)
//             {
//                 break;
//             }
//         }
//         return res;
//     }
// };