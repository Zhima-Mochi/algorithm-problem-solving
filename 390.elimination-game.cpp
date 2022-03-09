/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{

public:
    int lastRemaining(int n)
    {
        int start = 1;
        int step = 1;
        bool odd = true;
        while (n > 1)
        {
            if (odd || n % 2)
            {
                start += step;
            }
            step *= 2;
            odd = !odd;
            n /= 2;
        }
        return start;
    }
};
// @lc code=end
