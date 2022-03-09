/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution
{
    void helpler(int &n, int val)
    {
        while (n % val == 0)
        {
            n /= val;
        }
    }

public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n % 2 == 0)
        {
            for (int i = 30; i >= 1; --i)
            {
                helpler(n, 1 << i);
            }
        }
        if (n % 5 == 0)
        {
            helpler(n, 625);
            helpler(n, 25);
            helpler(n, 5);
        }
        if (n % 3 == 0)
        {
            helpler(n, 81);
            helpler(n, 27);
            helpler(n, 9);
            helpler(n, 3);
        }
        return n == 1;
    }
};
// @lc code=end
