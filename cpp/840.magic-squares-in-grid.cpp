/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(M*N) s:O(N)
class Solution
{
public:
    int h;
    int w;
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        h = grid.size();
        w = grid[0].size();
        if (h < 2 || w < 2)
        {
            return 0;
        }
        int res = 0;
        vector<int> goal(16);
        for (int i = 1; i <= 9; ++i)
        {
            goal[i] = 1;
        }
        vector<int> dp(16);
        vector<int> dp_r(w);
        vector<int> dp_c(w);

        for (int i = 0; i != h; ++i)
        {
            dp = vector<int>(16);
            dp_r = vector<int>(w);

            for (int j = 0; j != w; ++j)
            {
                dp_r[j] = grid[i][j] + (j > 0 ? dp_r[j - 1] : 0) - (j > 2 ? grid[i][j - 3] : 0);
                dp_c[j] = dp_c[j] + grid[i][j] - (i > 2 ? grid[i - 3][j] : 0);
                if (j > 2)
                {
                    for (int k = i; k >= i - 2 && k >= 0; --k)
                    {
                        dp[grid[k][j - 3]] = max(0, dp[grid[k][j - 3]] - 1);
                    }
                }
                for (int k = i; k >= i - 2 && k >= 0; --k)
                {
                    ++dp[grid[k][j]];
                }
                if (dp == goal)
                {
                    if (dp_r[j] == 15 && dp_c[j] == 15 && dp_c[j - 1] == 15)
                    {
                        if (grid[i][j] + grid[i - 2][j - 2] + grid[i - 1][j - 1] == 15 && grid[i - 2][j] + grid[i][j - 2] + grid[i - 1][j - 1] == 15)
                        {
                            ++res;
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
