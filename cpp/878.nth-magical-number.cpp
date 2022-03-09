/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */
#include <numeric>
#include <queue>
using namespace std;
// @lc code=start
#define mod 1000000007
class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        if (a > b)
        {
            swap(a, b);
        }
        long long lcm_val = lcm(a, b);
        long long unit_count = lcm_val / a + lcm_val / b - 1;
        long long lcm_times = (n / unit_count);
        n -= lcm_times * unit_count;

        long long one_time_add = static_cast<long long>(1000000) * mod / lcm_val;
        long long res = 0;

        while (lcm_times)
        {
            if (lcm_times >= one_time_add)
            {
                lcm_times -= one_time_add;
                res += one_time_add * lcm_val;
            }
            else
            {
                res += lcm_times * lcm_val;
                lcm_times = 0;
            }
            res %= mod;
        }

        int a_count = 1;
        int b_count = 1;
        long long add = 0;
        while (n--)
        {
            if (a * a_count < b * b_count)
            {
                add = a * a_count;
                ++a_count;
            }
            else
            {
                add = b * b_count;
                ++b_count;
            }
        }
        res += add;
        res %= mod;
        return res;
    }
};
// @lc code=end
