/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int a = 0, b = 0;

        for (auto n : nums)
        {
            a ^= n;
            a &= ~b;
            b ^= n;
            b &= ~a;
        }
        return a;
    }
};
// @lc code=end
