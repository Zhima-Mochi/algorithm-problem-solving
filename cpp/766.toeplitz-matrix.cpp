/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */
#include <vector>
using namespace std;

// @lc code=start
#if 0
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        for (int i = 1; i != height; ++i)
        {
            for (int j = 1; j != width; ++j)
            {
                if (matrix[i - 1][j - 1] != matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
#else
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        auto cur_vec = matrix[0];
        auto cur_tail = width - 1;
        for (int i = 1; i != height; ++i)
        {
            for (int m = cur_tail + 1; m != width; ++m)
            {
                if (matrix[i][m - cur_tail] != cur_vec[m])
                {
                    return false;
                }
            }

            for (int m = 0; m != cur_tail; ++m)
            {
                if (matrix[i][width - cur_tail + m] != cur_vec[m])
                {
                    return false;
                }
            }

            cur_vec[cur_tail] = matrix[i][0];
            if (cur_tail > 0)
            {
                --cur_tail;
            }
            else
            {
                cur_tail = width - 1;
            }
        }
        return true;
    }
};
#endif
// @lc code=end