/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum_val = 0;
        double res = INT64_MIN;
        int len = nums.size();
        for (int i = 0; i != k; ++i)
        {
            sum_val += nums[i];
        }
        res = max(res, sum_val);
        for (int i = k; i != len; ++i)
        {
            sum_val -= nums[i - k];
            sum_val += nums[i];
            res = max(res, sum_val);
        }
        return res / k;
    }
};
// @lc code=end
