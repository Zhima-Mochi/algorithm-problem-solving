/*
 * @lc app=leetcode id=2481 lang=cpp
 *
 * [2481] Minimum Cuts to Divide a Circle
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfCuts(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        else if (n % 2)
        {
            return n;
        }
        else
        {
            return n / 2;
        }
    }
};
// @lc code=end
