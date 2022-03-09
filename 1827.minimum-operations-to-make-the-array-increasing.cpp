/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int res = 0;
        int prev = 0;
        for (auto n : nums)
        {
            if (n > prev)
            {
                prev = n;
            }
            else
            {
                res += prev - n + 1;
                ++prev;
            }
        }
        return res;
    }
};
// @lc code=end
