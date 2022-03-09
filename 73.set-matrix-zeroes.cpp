/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        auto height = matrix.size(), width = matrix[0].size();
        auto first_row_has_zero = false, first_col_has_zero = false;
        for (int n = 0; n != height; n++)
        {
            if (matrix[n][0] == 0)
            {
                first_col_has_zero = true;
                break;
            }
        }
        for (int n = 0; n != width; n++)
        {
            if (matrix[0][n] == 0)
            {
                first_row_has_zero = true;
                break;
            }
        }
        for (int i = 1; i != height; ++i)
        {
            for (int j = 1; j != width; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i != height; ++i)
        {
            for (int j = 1; j != width; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_col_has_zero)
        {
            for (int n = 0; n != height; n++)
            {
                matrix[n][0] = 0;
            }
        }
        if (first_row_has_zero)
        {
            for (int n = 0; n != width; n++)
            {
                matrix[0][n] = 0;
            }
        }
    }
};
// @lc code=end
