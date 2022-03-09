/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n)
        {
            if (n % 2 == 1)
                ++cnt;
            n >>= 1;
        }
        return cnt;
    }
};
// @lc code=end
