/*
 * @lc app=leetcode id=2544 lang=cpp
 *
 * [2544] Alternating Digit Sum
 */

// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int res = 0;
        int w = 0;
        int c = 1;
        while (n)
        {
            res += c * (n % 10);
            c *= -1;
            w++;
            n /= 10;
        }
        if (w % 2 == 0)
        {
            res *= -1;
        }
        return res;
    }
};
// @lc code=end
