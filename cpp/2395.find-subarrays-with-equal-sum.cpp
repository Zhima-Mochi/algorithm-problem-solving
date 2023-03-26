/*
 * @lc app=leetcode id=2395 lang=cpp
 *
 * [2395] Find Subarrays With Equal Sum
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
// t: O(n), s: O(n)
class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        unordered_set<int> seen_sum;
        int w = nums.size();
        for (auto i = 1; i != w; ++i)
        {
            if (seen_sum.count(nums[i - 1] + nums[i]))
            {
                return true;
            }
            seen_sum.insert(nums[i - 1] + nums[i]);
        }
        return false;
    }
};
// @lc code=end
