/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */
#include <cmath>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
        {
            return n;
        }
        else
        {
            n -= 9;
        }
        int base = 10;
        short len = 2;
        while (len < 9 && n > len * base * 9)
        {
            n -= len * base * 9;
            base *= 10;
            ++len;
        }
        base += n / len;
        n %= len;
        if (n == 0)
        {
            base -= 1;
        }
        return n == 0 ? to_string(base)[len - 1] - '0' : to_string(base)[n - 1] - '0';
    }
};
// @lc code=end
