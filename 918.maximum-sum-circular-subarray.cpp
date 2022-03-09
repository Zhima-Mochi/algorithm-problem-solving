/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        long long sum_val = accumulate(nums.begin(), nums.end(), 0);
        int w = nums.size();
        return max({kadane_method(nums, 0, w - 1, 1), sum_val + kadane_method(nums, 1, w - 1, -1), sum_val + kadane_method(nums, 0, w - 2, -1)});
    }
    long long kadane_method(vector<int> nums, int left, int right, int sign)
    {
        int res = INT_MIN;
        int current_sum = INT_MIN;
        for (int i = left; i != right + 1; ++i)
        {
            current_sum = nums[i] * sign + max(0, current_sum);
            res = max(res, current_sum);
        }
        return res;
    }
};
// @lc code=end
