/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(1);
        for (int i = 1; i <= n; i++)
        {
            res[0].push_back(i);
        }
        auto row = 1;
        while (row <= (n - 1) / 2)
        {
            vector<int> new_row;
            for (int i = 0; i <= row - 2; i++)
            {
                new_row.push_back(res[row - 1][i] - 1);
            }
            auto count = res[row - 1][n - row] + 3 * (n - 2 * row) + 2;
            for (int i = row - 1; i <= n - row - 1; i++)
            {
                new_row.push_back(count++);
            }
            for (int i = n - row; i <= n - 1; i++)
            {
                new_row.push_back(res[row - 1][i] + 1);
            }
            res.push_back(new_row);
            ++row;
        }
        while (row < n)
        {
            vector<int> new_row;
            for (int i = 0; i <= n - 1 - row - 1; i++)
            {
                new_row.push_back(res[row - 1][i] - 1);
            }
            auto count = res[row - 1][row] + 1 + 2 * row - (n - 1);
            for (int i = n - 1 - row; i <= row; i++)
            {
                new_row.push_back(count--);
            }
            for (int i = row + 1; i <= n - 1; i++)
            {
                new_row.push_back(res[row - 1][i] + 1);
            }
            res.push_back(new_row);
            ++row;
        }
        return res;
    }
};
// @lc code=end
