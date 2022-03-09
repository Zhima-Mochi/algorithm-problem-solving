/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */
#include <bitset>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int band = left & right;
        int diff = right - left;
        if (band < diff)
        {
            return 0;
        }
        int pos = 1;
        while (diff)
        {
            band &= ~pos;
            pos <<= 1;
            diff /= 2;
        }
        return band;
    }
};
// @lc code=end
