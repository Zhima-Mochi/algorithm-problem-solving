/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        auto len = nums.size();
        int cur_max_val = nums[0];
        int max_val = nums[0];
        int res = 1;
        for (int i = 1; i != len; ++i)
        {
            if (nums[i] < cur_max_val)
            {
                res = i + 1;
                cur_max_val = max_val;
            }
            else
            {
                max_val = max(max_val, nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
