/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> seen;
        int sum_val = 0;
        seen[sum_val] = 1;
        int res = 0;
        for (auto n : nums)
        {
            sum_val += n;
            if (seen.count(sum_val - k))
            {
                res += seen[sum_val - k];
            }
            ++seen[sum_val];
        }
        return res;
    }
};
// @lc code=end
