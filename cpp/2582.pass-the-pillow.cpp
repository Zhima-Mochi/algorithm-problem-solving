/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        time %= 2 * (n - 1);
        if (time <= n - 1)
        {
            return 1 + time;
        }
        time -= (n - 1);
        return n - time;
    }
};
// @lc code=end
