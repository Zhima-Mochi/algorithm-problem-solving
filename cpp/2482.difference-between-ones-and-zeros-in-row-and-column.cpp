/*
 * @lc app=leetcode id=2482 lang=cpp
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(mn), s:O(m+n)
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> row_stat(m), col_stat(n);
        for (int i = 0; i != m; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                if (grid[i][j])
                {
                    row_stat[i]++;
                    col_stat[j]++;
                }
                else
                {
                    row_stat[i]--;
                    col_stat[j]--;
                }
            }
        }
        for (int i = 0; i != m; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                grid[i][j] = row_stat[i] + col_stat[j];
            }
        }
        return grid;
    }
};
// @lc code=end
