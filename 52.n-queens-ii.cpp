/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
#include <functional>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int totalNQueens(int n)
    {
        int res = 0;
        vector<bool> col_occ(n), slash_occ(2 * n - 1), backslash_occ(2 * n - 1);
        function<void(int, int)> flap = [&](int row, int col)
        {
            // row_occ[row] = !row_occ[row];
            col_occ[col] = !col_occ[col];
            slash_occ[n - row + col - 1] = !slash_occ[n - row + col - 1];
            backslash_occ[row + col] = !backslash_occ[row + col];
        };
        function<void(int)> backtracking = [&](int num)
        {
            if (num == 0)
            {
                ++res;
                return;
            }
            int i = n - num;
            for (int j = 0; j != n; ++j)
            {
                if (col_occ[j] || slash_occ[n - i + j - 1] || backslash_occ[i + j])
                {
                    continue;
                }
                flap(i, j);
                backtracking(num - 1);
                flap(i, j);
            }
        };
        backtracking(n);
        return res;
    }
};
// @lc code=end
