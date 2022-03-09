/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        unsigned bit_and = a & b;
        unsigned bit_xor = a ^ b;
        while (bit_and)
        {
            auto next_bit_and = bit_xor & (bit_and << 1);
            bit_xor ^= (bit_and << 1);
            bit_and = move(next_bit_and);
        }
        return bit_xor;
    }
};
// @lc code=end
