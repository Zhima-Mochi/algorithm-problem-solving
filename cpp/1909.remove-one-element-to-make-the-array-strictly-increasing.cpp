/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int bound = -1;
        int prev_bound = -1;
        int error = 0;
        for (auto n : nums)
        {
            if (n <= bound)
            {
                if (++error == 2)
                {
                    return false;
                }
                if (prev_bound < n)
                {
                    bound = n;
                }
            }
            else
            {
                prev_bound = bound;
                bound = n;
            }
        }
        return true;
    }
};
// @lc code=end
