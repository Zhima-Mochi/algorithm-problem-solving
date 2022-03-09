/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int accum_val = 0;
        int min_val = 0;
        for (auto &n : nums)
        {
            accum_val += n;
            min_val = min(min_val, accum_val);
        }
        return 1 - min_val;
    }
};
// @lc code=end
