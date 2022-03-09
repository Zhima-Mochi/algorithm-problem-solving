/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        vector<int> max_vals = {-1, -1};
        vector<int> min_vals = {100000, 100000};
        for (auto n : nums)
        {
            if (n >= max_vals[0])
            {
                max_vals[1] = max_vals[0];
                max_vals[0] = n;
            }
            else if (n > max_vals[1])
            {
                max_vals[1] = n;
            }

            if (n <= min_vals[0])
            {
                min_vals[1] = min_vals[0];
                min_vals[0] = n;
            }
            else if (n < min_vals[1])
            {
                min_vals[1] = n;
            }
        }
        return max_vals[0] * max_vals[1] - min_vals[0] * min_vals[1];
    }
};
// @lc code=end
