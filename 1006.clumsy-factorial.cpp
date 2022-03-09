/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    int clumsy(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else if (n == 3)
        {
            return 6;
        }
        else if (n == 4)
        {
            return 7;
        }
        int res = n * (n - 1) / (n - 2) + n - 3;
        if (n % 4 == 1)
        {
            res -= 1;
            n -= 1;
        }
        else if (n % 4 == 2)
        {
            res -= 2;
            n -= 2;
        }
        else if (n % 4 == 3)
        {
            res -= 6;
            n -= 3;
        }
        else
        {
            res -= 5;
            n -= 4;
        }
        res += -4 * ((n - 4) / 4);
        return res;
    }
};
// @lc code=end
