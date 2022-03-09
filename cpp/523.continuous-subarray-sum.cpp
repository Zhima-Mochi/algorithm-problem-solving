/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int width = nums.size();
        unordered_set<int> seen;
        seen.insert(nums[0] % k);
        int shift = 0;
        for (int i = 1; i != width; ++i)
        {
            shift += nums[i];
            shift %= k;
            if (seen.count((-shift + k) % k))
            {
                return true;
            }
            seen.insert((-shift + k + nums[i]) % k);
        }
        return false;
    }
};
// @lc code=end
