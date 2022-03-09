/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int count = 0;
        bool pass = false;
        int prev_pass_distance = 0;
        int res = 0;
        for (auto &&n : nums)
        {
            if (n <= right)
            {
                ++count;
                if (n >= left)
                {
                    res += count;
                    pass = true;
                    prev_pass_distance = 0;
                }
                else if (pass)
                {
                    ++prev_pass_distance;
                    res += count - prev_pass_distance;
                }
            }
            else
            {
                count = 0;
                pass = false;
            }
        }
        return res;
    }
};
// @lc code=end