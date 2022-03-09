/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<bool> row_odd(m);
        vector<bool> col_odd(n);
        for (auto &vec : indices)
        {
            row_odd[vec[0]] = !row_odd[vec[0]];
            col_odd[vec[1]] = !col_odd[vec[1]];
        }
        int row_odd_count = 0;
        int col_odd_count = 0;
        for (auto b : row_odd)
        {
            if (b)
            {
                ++row_odd_count;
            }
        }
        for (auto b : col_odd)
        {
            if (b)
            {
                ++col_odd_count;
            }
        }
        return row_odd_count * (n - col_odd_count) + col_odd_count * (m - row_odd_count);
    }
};
// @lc code=end
