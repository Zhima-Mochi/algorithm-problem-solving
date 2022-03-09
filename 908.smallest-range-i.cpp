/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int max_val = nums[0];
        int min_val = max_val;
        for (auto &n : nums)
        {
            if (n > max_val)
            {
                max_val = n;
            }
            else if (n < min_val)
            {
                min_val = n;
            }
        }
        return max(0, max_val - min_val - 2 * k);
    }
};
// @lc code=end
