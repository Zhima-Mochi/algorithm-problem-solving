/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // auto len = nums.size();
        // int val = 0;
        // for (auto i = 0; i != len; ++i)
        // {
        //     val ^= (i ^ nums[i]);
        // }
        // return val ^ len;
        int total_sum = (nums.size()) * (nums.size() + 1) / 2;
        for (auto &n : nums)
        {
            total_sum -= n;
        }
        return total_sum;
    }
};
// @lc code=end
