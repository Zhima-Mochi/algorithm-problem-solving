/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <cmath>
// @lc code=start
class Solution
{
    int C(int n, int m)
    {
        long double res = 1;
        while (m != 0)
        {
            res *= n--;
            res /= m--;
        }
        return round(res);
    }

public:
    //Can use recursion of combination to prove it is Fibonacci array
    int climbStairs(int n)
    {
        int res = 1;
        int bound = n / 2;
        for (int count_2 = 1; count_2 <= bound; count_2++)
        {
            res += C(n - count_2, count_2);
        }
        return res;
    }
};
// @lc code=end
