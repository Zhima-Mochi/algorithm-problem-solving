/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = min(num, 46340);
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (mid * mid < num)
            {
                left = mid + 1;
            }
            else if (mid * mid > num)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return left * left == num;
        // for (int i = 1; i <= 46340 && i * i <= num; ++i)
        // {
        //     if (i * i == num)
        //     {
        //         return true;
        //     }
        // }
        // return false;
    }
};
// @lc code=end
