/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int w = nums.size();
        vector<int> increasing_val_idx = {w - 1};
        int res = 0;
        for (int i = w - 2; i > -1; --i)
        {
            if (nums[i] > nums[increasing_val_idx.back()])
            {
                increasing_val_idx.push_back(i);
            }
            else
            {
                int ge_idx = *lower_bound(increasing_val_idx.begin(), increasing_val_idx.end(), i, [&](int i, int j)
                                          { return nums[i] < nums[j]; });
                res = max(res, ge_idx - i);
            }
        }
        return res;
    }
};
// @lc code=end
