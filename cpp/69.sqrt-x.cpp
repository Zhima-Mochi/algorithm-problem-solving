/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 2, right = min(x / 2, static_cast<int>(sqrt(INT_MAX)));
        if (x <= 1)
        {
            return x;
        }
        if (left == right)
        {
            return left;
        }
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            if (middle > x / middle)
            {
                right = middle;
            }
            else if (middle == x / middle)
            {
                return middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        if (left * left <= x)
        {
            return left;
        }
        return left - 1;
    }
};
// @lc code=end
