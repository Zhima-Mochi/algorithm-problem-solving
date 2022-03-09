/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int width = nums.size();
        vector<int> accum_nums(width - k + 1);
        accum_nums[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        for (int i = k; i != width; ++i)
        {
            accum_nums[i - k + 1] = accum_nums[i - k] + nums[i] - nums[i - k];
        }
        int x = 0, y = k, z = 2 * k;
        int cand_x = 0, cand_y = k;
        int cand_cand_x = 0;
        for (int i = 0; i != width - 3 * k + 1; ++i)
        {
            if (accum_nums[i] > accum_nums[cand_cand_x])
            {
                cand_cand_x = i;
            }
            if (accum_nums[cand_cand_x] + accum_nums[k + i] > accum_nums[cand_x] + accum_nums[cand_y])
            {
                cand_x = cand_cand_x;
                cand_y = k + i;
            }
            if (accum_nums[2 * k + i] + accum_nums[cand_x] + accum_nums[cand_y] > accum_nums[z] + accum_nums[x] + accum_nums[y])
            {
                z = 2 * k + i;
                x = cand_x;
                y = cand_y;
            }
        }
        return {x, y, z};
    }
};
// @lc code=end