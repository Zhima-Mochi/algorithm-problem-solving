/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        if (nums.back() > nums.front())
        {
            for (auto iter = next(nums.begin()); iter != nums.end(); ++iter)
            {
                if (*iter < *prev(iter))
                {
                    return false;
                }
            }
        }
        else if (nums.back() == nums.front())
        {
            for (auto iter = next(nums.begin()); iter != nums.end(); ++iter)
            {
                if (*iter != *prev(iter))
                {
                    return false;
                }
            }
        }
        else
        {
            for (auto iter = next(nums.begin()); iter != nums.end(); ++iter)
            {
                if (*iter > *prev(iter))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
