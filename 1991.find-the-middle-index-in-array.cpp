/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int right_sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        for (int i = 0, width = nums.size(); i != width; ++i)
        {
            right_sum -= nums[i];
            if (left_sum == right_sum)
            {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end
