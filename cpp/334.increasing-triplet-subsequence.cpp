/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int current_middle = INT_MAX;
        int current_min = INT_MAX;
        for (auto &n : nums)
        {
            if (n <= current_min)
            {
                if (n != current_min)
                    current_min = n;
            }
            else if (n <= current_middle)
            {
                if (n != current_middle)
                    current_middle = n;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
