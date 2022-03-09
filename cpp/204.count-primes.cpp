/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }
        vector<bool> is_not_prime(n);
        auto anti_count = 0;
        for (int j = 2; j * 2 < n; j++)
        {
            if (is_not_prime[j * 2] == false)
            {
                is_not_prime[j * 2] = true;
                anti_count--;
            }
        }
        int i = 3;
        for (; i * i <= n; ++i)
        {
            if (is_not_prime[i] == false)
            {
                for (int j = i; j * i < n; j += 2)
                {
                    if (is_not_prime[j * i] == false)
                    {
                        is_not_prime[j * i] = true;
                        anti_count--;
                    }
                }
            }
        }
        return n - 1 - 1 + anti_count;
    }
};
// @lc code=end
