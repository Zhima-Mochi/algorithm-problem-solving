/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // int bound = 1073741824;
        // while (bound != 1)
        // {
        //     if (n % bound == 0)
        //     {
        //         n /= bound;
        //     }
        //     bound /= 4;
        // }
        // return n == 1;
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};
// @lc code=end
