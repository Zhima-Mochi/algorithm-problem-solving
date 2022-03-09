/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include <vector>
using namespace std;
// @lc code=start
class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix) : m(vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size())))
    {
        int height = matrix.size();
        int width = matrix[0].size();
        for (int i = 0; i != height; ++i)
        {
            m[i][0] = matrix[i][0];
            for (int j = 1; j != width; ++j)
            {
                m[i][j] = m[i][j - 1] + matrix[i][j];
            }
            if (i > 0)
            {
                for (int j = 0; j != width; ++j)
                {
                    m[i][j] += m[i - 1][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum_val = m[row2][col2];
        if (row1 > 0)
        {
            sum_val -= m[row1 - 1][col2];
        }
        if (col1 > 0)
        {
            sum_val -= m[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0)
        {
            sum_val += m[row1 - 1][col1 - 1];
        }
        return sum_val;
    }
    vector<vector<int>> m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
