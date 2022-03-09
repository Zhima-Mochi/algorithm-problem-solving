/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int count = sqrt(n) * 1.4 - 1;
        if (count % 2 == 0)
        {
            n -= (count / 2) * (count + 1);
        }
        else
        {
            n -= count * ((count + 1) / 2);
        }
        ++count;
        while (n >= count)
        {
            n -= count;
            ++count;
        }
        return count - 1;
    }
};
// @lc code=end
