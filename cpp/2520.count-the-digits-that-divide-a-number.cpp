/*
 * @lc app=leetcode id=2520 lang=cpp
 *
 * [2520] Count the Digits That Divide a Number
 */

// @lc code=start
class Solution
{
public:
    int countDigits(int num)
    {
        int res = 0;
        int n = num;
        while (n)
        {
            if (num % (n % 10) == 0)
            {
                res++;
            }
            n /= 10;
        }
        return res;
    }
};
// @lc code=end
