/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {

        int f[] = {1, 0};
        while (n)
        {
            auto temp = f[1];
            f[1] = f[0] + f[1];
            f[0] = temp;
            --n;
        }
        return f[1];
    }
};
// @lc code=end
