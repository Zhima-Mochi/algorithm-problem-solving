/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int height = matrix.size();
        if (height == 0)
        {
            return 0;
        }
        int width = matrix[0].size();
        int **dp = new int *[width];
        for (int i = 0; i != width; ++i)
        {
            dp[i] = new int[width]{0};
        }
        // vector<vector<int>> dp(width, vector<int>(width));
        int res = 0;
        for (int i = 0; i != height; ++i)
        {
            int zero_ind = -1;
            for (int j = 0; j != width; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    for (int k = j; k != zero_ind; --k)
                    {
                        dp[j][k] += 1 * (j - k + 1);
                    }
                }
                else
                {
                    zero_ind = j;
                }
                for (int k = zero_ind; k != -1; --k)
                {
                    if (dp[j][k] == 0)
                    {
                        break;
                    }
                    res = max(res, dp[j][k]);
                    dp[j][k] = 0;
                }
            }
        }
        for (int j = 0; j != width; ++j)
        {
            for (int k = j; k != -1; --k)
            {
                if (dp[j][k] == 0)
                {
                    break;
                }
                res = max(res, dp[j][k]);
            }
        }
        return res;
    }
};
// @lc code=end
