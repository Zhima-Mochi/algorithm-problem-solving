/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int arr[46] = {};

public:
    int countBalls(int lowLimit, int highLimit)
    {
        for (int i = lowLimit; i <= highLimit; ++i)
        {
            ++arr[box_number(i)];
        }
        return *max_element(begin(arr), end(arr));
    }
    int box_number(int val)
    {
        int res = 0;
        while (val)
        {
            res += val % 10;
            val /= 10;
        }
        return res;
    }
};
// @lc code=end
