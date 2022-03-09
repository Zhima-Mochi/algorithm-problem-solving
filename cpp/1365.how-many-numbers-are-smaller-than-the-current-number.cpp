/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (auto &n : nums)
        {
            n = lower_bound(sorted.begin(), sorted.end(), n) - sorted.begin();
        }
        return nums;
    }
};
// @lc code=end
