/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */
#include <vector>
#include <numeric>
#include <climits>
using namespace std;
// @lc code=start
// t:O(N*N*N), s:O(N*N)
class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int w = values.size();
        if (w < 3)
        {
            return 0;
        }
        else if (w == 3)
        {
            return accumulate(values.begin(), values.end(), 1, multiplies<int>());
        }
        vector<vector<int>> dp(w, vector<int>(w, 0));
        for (int r = 2; r != w; ++r)
        {
            for (int l = r - 2; l > -1; --l)
            {
                dp[l][r] = INT_MAX;
                for (int m = l + 1; m < r; ++m)
                {
                    dp[l][r] = min(dp[l][r], values[l] * values[r] * values[m] + dp[l][m] + dp[m][r]);
                }
            }
        }
        return dp[0][w - 1];
    }
};
// @lc code=end
