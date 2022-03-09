/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 */
#include <vector>
#include <array>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        array<bool, 100001> bobCandy;
        bobCandy.fill(false);
        int alice_sum_candy = 0, bob_sum_candy = 0;

        for (auto &n : aliceSizes)
        {
            alice_sum_candy += n;
        }
        for (auto &n : bobSizes)
        {
            bob_sum_candy += n;
            bobCandy[n] = true;
        }
        int diff_num = bob_sum_candy - alice_sum_candy;
        for (auto &n : aliceSizes)
        {
            if (diff_num / 2 + n > 0 && diff_num / 2 + n <= 100000 && bobCandy[diff_num / 2 + n])
            {
                return {n, diff_num / 2 + n};
            }
        }
        return {0, 0};
    }
};
// @lc code=end
