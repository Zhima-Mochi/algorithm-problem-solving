/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// @lc code=start
// t:O(m*n), s:O(1)
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int h = matrix.size(), w = matrix[0].size();
        int negative_cnt = 0;
        int abs_min = INT_MAX;
        long long res = 0;
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (matrix[i][j] >= 0)
                {
                    res += matrix[i][j];
                }
                else
                {
                    negative_cnt += 1;
                    negative_cnt %= 2;
                    res -= matrix[i][j];
                }
                abs_min = min(abs_min, abs(matrix[i][j]));
            }
        }
        if (negative_cnt == 0)
        {
            return res;
        }
        else
        {
            res -= 2 * abs_min;
        }
        return res;
    }
};
// @lc code=end
