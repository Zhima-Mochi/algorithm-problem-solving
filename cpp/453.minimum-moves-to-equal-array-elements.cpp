/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int len = nums.size();
        int res = 0;
        int min_val = nums[0];
        for (auto &n : nums)
        {
            res += n;
            min_val = min(min_val, n);
        }
        res -= len * min_val;
        return res;
        
        // sort(nums.begin(), nums.end());
        // int len = nums.size();
        // int res = 0;
        // int prev_accum = 0;
        // for (int i = 1; i != len; ++i)
        // {
        //     res += nums[i] - nums[0];
        //     //res += prev_accum + nums[i] - nums[i - 1];
        //     //prev_accum += nums[i] - nums[i - 1];
        // }
        // return res;
    }
};
// @lc code=end
