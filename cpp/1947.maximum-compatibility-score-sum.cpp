/*
 * @lc app=leetcode id=1947 lang=cpp
 *
 * [1947] Maximum Compatibility Score Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int has_matched = 0;
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> memo(m, vector<int>(m));
        for (int i = 0; i != m; ++i)
        {
            for (int j = 0; j != m; ++j)
            {
                int s = 0;
                for (int k = 0; k != n; ++k)
                {
                    if (students[i][k] == mentors[j][k])
                    {
                        s++;
                    }
                }
                memo[i][j] = s;
            }
        }
        vector<int> dp(1 << m);
        for (int i = 0; i != 1 << m; ++i)
        {
            for (int j = 0; j != m; ++j)
            {
                if (i & (1 << j))
                {
                    int s = __builtin_popcount(i);
                    dp[i] = max(dp[i], dp[i ^ (1 << j)] + memo[s - 1][j]);
                }
            }
        }
        return dp[(1 << m) - 1];
    }
};
// @lc code=end
