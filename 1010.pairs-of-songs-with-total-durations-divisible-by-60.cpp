/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int rd[60] = {};

public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int res = 0;
        for (auto t : time)
        {
            res += rd[(60 - t % 60) % 60];
            ++rd[t % 60];
        }
        return res;
    }
};
// @lc code=end
