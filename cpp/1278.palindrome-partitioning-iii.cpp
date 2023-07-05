/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int palindromePartition(string s, int k)
    {
        int w = s.size();
        vector<vector<int>> records(w, vector<int>(w, -1));
        for (int i = 0; i != w; ++i)
        {
            records[i][i] = 0;
        }
        for (int i = 1; i != w; ++i)
        {
            for (int j = 0; j + i != w; ++j)
            {
                if (s[j] == s[j + i])
                {
                    if (i == 1)
                    {
                        records[j][j + i] = 0;
                    }
                    else
                    {
                        records[j][j + i] = records[j + 1][j + i - 1];
                    }
                }
                else
                {
                    if (i == 1)
                    {
                        records[j][j + i] = 1;
                    }
                    else
                    {
                        records[j][j + i] = records[j + 1][j + i - 1] + 1;
                    }
                }
            }
        }
        vector<vector<int>> dp(w + 1, vector<int>(k + 1, -1));
        dp[0][0] = 0;
        for (int i = 1; i != w + 1; ++i)
        {
            for (int j = i - 1; j != -1; --j)
            {
                for (int m = 0; m != k; ++m)
                {
                    if (m > j)
                    {
                        break;
                    }
                    if (dp[j][m] == -1)
                    {
                        continue;
                    }
                    if (dp[i][m + 1] == -1)
                    {
                        dp[i][m + 1] = dp[j][m] + records[j][i - 1];
                    }
                    else
                    {
                        dp[i][m + 1] = min(dp[i][m + 1], dp[j][m] + records[j][i - 1]);
                    }
                }
            }
        }
        return dp[w][k];
    }
};
// @lc code=end
