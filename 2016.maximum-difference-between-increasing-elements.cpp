/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 */
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int min_val = INT_MAX;
        int res = -1;
        for (auto n : nums)
        {
            if (n > min_val)
            {
                res = max(res, n - min_val);
            }
            else if (n < min_val)
            {
                min_val = n;
            }
        }
        return res;
    }
};
// @lc code=end
