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
//O(log(n)) time complexity
    double myPow(double x, int n)
    {
        long double res = 1;
        auto step = 1;
        if (n == 0)
        {
            return res;
        }
        else if (x == 1)
        {
            return 1;
        }
        else if (x == -1)
        {
            return -2 * (n % 2) + 1;
        }
        if (n < 0)
        {
            res/=x;
            ++n *= -1;
            x = 1 / x;
        }
        long double multiplier = x;
        while (n > 0)
        {
            while (n - 2 * step >= 0)
            {
                multiplier *= multiplier;
                if (abs(multiplier - 1) < 1e-10)
                {
                    return res;
                }else if(abs(res*multiplier)<1e-10){
                    return 0;
                }
                step *= 2;
            }
            res *= multiplier;
            n -= step;
            step = 1;
            multiplier = x;
        }
        return res;
    }
};
// @lc code=end
