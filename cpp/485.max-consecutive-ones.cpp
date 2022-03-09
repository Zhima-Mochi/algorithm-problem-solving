/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int res = 0;
        for (auto n : nums)
        {
            if (n == 1)
            {
                ++count;
            }
            else
            {
                res = max(count, res);
                count = 0;
            }
        }
        return max(count, res);
    }
};
// @lc code=end
