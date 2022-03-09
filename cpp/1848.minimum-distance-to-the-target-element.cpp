/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int width = nums.size();
        int res = width;
        for (int i = 0; i < min(width, start + res); ++i)
        {
            if (nums[i] == target)
            {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};
// @lc code=end
