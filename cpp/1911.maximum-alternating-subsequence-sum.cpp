/*
 * @lc app=leetcode id=1911 lang=cpp
 *
 * [1911] Maximum Alternating Subsequence Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int w = nums.size();
        long long odd = 0;
        long long even = nums[0];
        for (int i = 1; i != w; ++i)
        {
            auto og_even = even;
            even = max({odd + nums[i], even, static_cast<long long>(nums[i])});
            odd = max({odd, og_even - nums[i]});
        }
        return even;
    }
};
// @lc code=end
