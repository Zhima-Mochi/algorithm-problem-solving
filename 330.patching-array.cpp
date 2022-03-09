/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int count = 0, i = 0;
        int len = nums.size();
        long long max_val = 0;
        while (max_val < n && i < len)
        {
            if (nums[i] <= max_val + 1)
                max_val += nums[i++];
            else
            {
                max_val += max_val + 1;
                ++count;
            }
        }
        while (max_val < n)
        {
            max_val += max_val + 1;
            ++count;
        }
        return count;
    }
};
// @lc code=end
