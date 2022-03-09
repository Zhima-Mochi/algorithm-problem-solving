/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int disc_cnt = 0;
        int prev = INT_MIN;
        for (auto n : nums)
        {
            if (n < prev)
            {
                if (++disc_cnt == 2)
                {
                    return false;
                }
            }
            if (disc_cnt == 1 && n > nums[0])
            {
                return false;
            }
            prev = n;
        }
        return true;
    }
};
// @lc code=end
