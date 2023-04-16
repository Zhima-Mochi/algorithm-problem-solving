/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
// t: O(m*n), s: O(n)
long long mod = 1000000007;
class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        int w = words[0].size();
        if (w < target.size())
        {
            return 0;
        }
        vector<vector<long long>> records(w + 1, vector<long long>(26, 0));
        for (auto &word : words)
        {
            for (int i = 1; i != w + 1; ++i)
            {
                records[i][word[i - 1] - 'a'] += 1;
            }
        }
        int target_w = target.size();
        vector<long long> dp(w + 1, 0);
        vector<long long> accum(w + 1, 0);
        for (int i = 1; i != target_w + 1; ++i)
        {
            if (i == 1)
            {
                for (int j = 1; j != w + 1; ++j)
                {
                    dp[j] = records[j][target[i - 1] - 'a'];
                    accum[j] = accum[j - 1] + dp[j];
                }
            }
            else
            {
                for (int j = w; j != i - 1; --j)
                {

                    dp[j] = (accum[j - 1] - accum[i - 2]) * records[j][target[i - 1] - 'a'];
                    dp[j] %= mod;
                }
                accum[i - 1] = 0;
                for (int j = i; j != w + 1; ++j)
                {
                    accum[j] = accum[j - 1] + dp[j];
                    accum[j] %= mod;
                }
            }
        }
        long long result = 0;
        for (int i = target_w; i != w + 1; ++i)
        {
            result += dp[i];
            result %= mod;
        }
        return result;
    }
};
// @lc code=end
