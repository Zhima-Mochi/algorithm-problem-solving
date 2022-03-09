/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(1)
class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int max_val = nums.back();
        int min_val = nums[0];
        int res = max_val - min_val;
        int w = nums.size();
        for (int i = 0; i < w - 1; ++i)
        {
            max_val = max(nums[i] + k, nums.back() - k);
            min_val = min(nums[i + 1] - k, nums[0] + k);
            res = min(res, max_val - min_val);
        }
        return res;
    }
};
// @lc code=end
