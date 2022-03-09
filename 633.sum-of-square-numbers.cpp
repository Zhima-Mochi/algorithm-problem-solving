/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */
#include <cmath>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        // fermat's theorem
        for (int i = 2; i * i <= c; i++)
        {
            int count = 0;
            if (c % i == 0)
            {
                while (c % i == 0)
                {
                    ++count;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};
// @lc code=end
