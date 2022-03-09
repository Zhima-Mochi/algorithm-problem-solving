/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int two_xor = 0;
        for (auto &n : nums)
        {
            two_xor ^= n;
        }
        int mask = 1;
        while (!(mask & two_xor))
        {
            mask <<= 1;
        }
        vector<int> res(2);
        for (auto &n : nums)
        {
            if (mask & n)
            {
                res[0] ^= n;
            }
            else
            {
                res[1] ^= n;
            }
        }
        return res;
    }
};
// @lc code=end
