/*
 * @lc app=leetcode id=2457 lang=cpp
 *
 * [2457] Minimum Addition to Make Integer Beautiful
 */

// @lc code=start
// t:O(log(n)^2), s:O(1)
class Solution
{
public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long mul = 1;
        long long res = 0;
        while (digitsSum(n) > target)
        {
            res += (10 - n % 10) * mul;
            mul *= 10;
            n /= 10;
            n += 1;
        }
        return res;
    }
    int digitsSum(long long n)
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};
// @lc code=end
