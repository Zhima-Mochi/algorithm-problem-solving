/*
 * @lc app=leetcode id=2485 lang=cpp
 *
 * [2485] Find the Pivot Integer
 */

// @lc code=start
// t:O(log(n)), s:O(1)
class Solution
{
public:
    int pivotInteger(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            long long l_s = (1 + mid) * mid;
            long long r_s = (mid + n) * (n - mid + 1);
            if (l_s < r_s)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        long long l_s = (1 + left) * left;
        long long r_s = (left + n) * (n - left + 1);
        if (l_s == r_s)
        {
            return left;
        }
        return -1;
    }
};
// @lc code=end
