/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{

public:
    int minimumDeleteSum(string s1, string s2)
    {
        int res = 0;
        string ns1, ns2;
        for (auto c : s1)
        {
            if (s2.find(c) != -1)
            {
                ns1.push_back(c);
            }
            else
            {
                res += c;
            }
        }
        for (auto c : s2)
        {
            if (ns1.find(c) != -1)
            {
                ns2.push_back(c);
            }
            else
            {
                res += c;
            }
        }
        int ns1_w = ns1.size();
        int ns2_w = ns2.size();
        int max_width = max(ns1_w, ns2_w);
        vector<vector<int>> dp(ns1_w + 1, vector<int>(ns2_w + 1));
        dp[0][0] = res;
        for (int i = 1; i != ns1_w + 1; ++i)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][0] += ns1[i - 1];
        }
        for (int i = 1; i != ns2_w + 1; ++i)
        {
            dp[0][i] = dp[0][i - 1];
            dp[0][i] += ns2[i - 1];
        }
        for (int i = 1; i <= ns1_w; ++i)
        {
            for (int j = 1; j <= ns2_w; ++j)
            {
                dp[i][j] = min(dp[i - 1][j] + ns1[i - 1], dp[i][j - 1] + ns2[j - 1]);
                if (ns1[i - 1] == ns2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[ns1_w][ns2_w];
    }
};
// @lc code=end
