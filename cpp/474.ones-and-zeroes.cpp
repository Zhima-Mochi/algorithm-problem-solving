/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto &s : strs)
        {
            int zero_count = 0, one_count = 0;
            for (auto c : s)
            {
                if (c == '0')
                {
                    ++zero_count;
                }
            }
            one_count = s.size() - zero_count;
            for (int i = m - zero_count; i > -1; --i)
            {
                for (int j = n - one_count; j > -1; --j)
                {
                    if (dp[i][j] + 1 > dp[i + zero_count][j + one_count])
                    {
                        dp[i + zero_count][j + one_count] = dp[i][j] + 1;
                    }
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
