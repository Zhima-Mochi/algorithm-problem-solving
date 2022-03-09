/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    static int mod;

public:
    int numPrimeArrangements(int n)
    {
        int prime_count = n - 1;
        vector<bool> seen(n + 1, false);
        for (int i = 4; i <= n; i += 2)
        {
            prime_count -= 1;
            seen[i] = true;
        }
        for (int i = 3; i <= n; i += 2)
        {
            if (seen[i])
            {
                --prime_count;
                continue;
            }
            else
            {
                for (int j = 3; i * j <= n; j += 2)
                {
                    seen[i * j] = true;
                }
            }
        }
        long sum_1 = 1, sum_2 = 1;
        for (int i = 1; i <= prime_count; ++i)
        {
            sum_1 *= i;
            sum_1 %= mod;
        }
        for (int i = 1; i <= n - prime_count; ++i)
        {
            sum_2 *= i;
            sum_2 %= mod;
        }
        return sum_1 * sum_2 % mod;
    }
};
int Solution::mod = 1000000007;
// @lc code=end
