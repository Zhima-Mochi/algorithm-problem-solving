/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */
#include <vector>
using namespace std;
// @lc code=start
int MOD = 1000000007;
class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        vector<long long> memo(n + 1, 0);
        memo[0] = 1;

        for (int i = 0; i != goal; ++i)
        {
            for (int j = n; j != 0; --j)
            {
                memo[j] *= max(j - k, 0);
                memo[j] += memo[j - 1] * (n - j + 1);
                memo[j] %= MOD;
            }
            memo[0] = 0;
        }
        return memo[n];
    }
};
// @lc code=end
