/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 10;
        }
        else if (n == 2)
        {
            return 91;
        }
        else
        {
            int copy_n = n - 2;
            int res = 81;
            int kind = 9;
            while (copy_n--)
            {
                res *= --kind;
            }
            return res + countNumbersWithUniqueDigits(n - 1);
        }
    }
};
// @lc code=end
