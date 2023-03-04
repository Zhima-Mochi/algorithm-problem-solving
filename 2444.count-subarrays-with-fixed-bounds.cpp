/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int w = nums.size();

        int last_min_pos = -1, last_max_pos = -1;
        long long res = 0;
        int left_pos = 0;
        for (int right_pos = 0; right_pos < w; ++right_pos)
        {
            if (nums[right_pos] > maxK || nums[right_pos] < minK)
            {
                last_min_pos = -1;
                last_max_pos = -1;
                left_pos = right_pos + 1;
                continue;
            }
            if (nums[right_pos] == maxK)
            {
                last_max_pos = right_pos;
            }
            if (nums[right_pos] == minK)
            {
                last_min_pos = right_pos;
            }
            if (last_min_pos != -1 && last_max_pos != -1)
            {
                res += (right_pos - left_pos) + 1;
                res -= (right_pos - min(last_max_pos, last_min_pos));
            }
        }
        return res;
    }
};
// @lc code=end
