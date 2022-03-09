/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int sum = 0;
        for (auto &n : nums)
        {
            sum = n += sum;
        }
        return nums;
    }
};
// @lc code=end
