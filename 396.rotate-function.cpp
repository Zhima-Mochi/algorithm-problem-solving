/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int width = nums.size();
        int sum_val = 0;
        int res = 0;
        for (int i = 0; i != width; ++i)
        {
            sum_val += nums[i];
            res += i * nums[i];
        }
        int cur_val = res;
        for (int i = 1; i != width; ++i)
        {
            cur_val += sum_val;
            cur_val -= width * nums[width - i];
            res = max(res, cur_val);
        }
        return res;
    }
};
// @lc code=end
