/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = 100000;
        for (int i = 0, width = nums.size(); i != width - k + 1; ++i)
        {
            res = min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};
// @lc code=end
