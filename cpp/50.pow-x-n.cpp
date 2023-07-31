/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    // O(log(n)) time complexity
    double myPow(double x, int n)
    {
        long double res = 1;
        long long num = n;
        long long step = 1;
        if (num == 0)
        {
            return res;
        }
        else if (x == 1)
        {
            return 1;
        }
        else if (x == -1)
        {
            return -2 * (num % 2) + 1;
        }
        if (num < 0)
        {
            res /= x;
            ++num *= -1;
            x = 1 / x;
        }
        long double multiplier = x;
        while (num > 0)
        {
            while (num - 2 * step >= 0)
            {
                multiplier *= multiplier;
                if (abs(multiplier - 1) < 1e-15)
                {
                    return res;
                }
                else if (abs(res * multiplier) < 1e-15)
                {
                    return 0;
                }
                step *= 2;
            }
            res *= multiplier;
            num -= step;
            step = 1;
            multiplier = x;
        }
        return res;
    }
};
// @lc code=end
