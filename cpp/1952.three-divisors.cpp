/*
 * @lc app=leetcode id=1952 lang=cpp
 *
 * [1952] Three Divisors
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isThree(int n)
    {
        if (n <= 3)
        {
            return false;
        }
        else
        {
            int val = round(pow(n, 0.5));
            if (val * val == n && isPrime(val))
            {
                return true;
            }
        }
        return false;
    }
    bool isPrime(int n)
    {
        if (n == 1)
        {
            return false;
        }
        if (n == 2)
        {
            return true;
        }
        if (n % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i <= pow(n + 0.1, 0.5); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
