/*
 * @lc app=leetcode id=1420 lang=cpp
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */
#include <vector>
#include <cstring>
using namespace std;
// @lc code=start
// t:O(mnk), s:O(mnk)
class Solution
{
    int MOD = 1000000007;

public:
    int numOfArrays(int n, int m, int k)
    {
        if (k > m)
        {
            return 0;
        }
        long long memo[51][101][51];
        memset(memo, 0, sizeof(memo));
        for (int i = 1; i <= m; ++i)
        {
            memo[0][i][1] = 1;
        }
        long long res = 0;
        for (int i = 1; i != n; ++i)
        {
            for (int g = k; g > 0; --g)
            {
                long long prev = 0;
                for (int j = 1; j <= m; ++j)
                {
                    memo[i][j][g] = memo[i - 1][j][g] * j;
                    memo[i][j][g] += prev;
                    memo[i][j][g] %= MOD;
                    prev += memo[i - 1][j][g - 1];
                    prev %= MOD;
                }
            }
        }
        for (int i = 0; i != m + 1; ++i)
        {
            res += memo[n - 1][i][k];
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end
