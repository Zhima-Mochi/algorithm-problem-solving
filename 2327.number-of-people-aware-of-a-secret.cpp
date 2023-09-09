/*
 * @lc app=leetcode id=2327 lang=cpp
 *
 * [2327] Number of People Aware of a Secret
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
    int MOD = 1000000007;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int accum[n + 1];
        accum[0] = 0, accum[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int f = (accum[max(i - delay, 0)] - accum[max(i - forget, 0)]) % MOD;
            accum[i] = (accum[i - 1] + f) % MOD;
        }
        return ((accum[n] - accum[max(n - forget, 0)]) % MOD + MOD) % MOD;
    }
};
// @lc code=end
