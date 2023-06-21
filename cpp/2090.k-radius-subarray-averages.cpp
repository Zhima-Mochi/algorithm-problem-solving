/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int w = nums.size();
        vector<long long> accum(w + 1);
        for (int i = 1; i != w + 1; ++i)
        {
            accum[i] = accum[i - 1] + nums[i - 1];
        }
        vector<int> res(w, -1);
        for (int i = 0; i != w; ++i)
        {
            if (i < k)
            {
                continue;
            }
            if (i + k >= w)
            {
                break;
            }
            res[i] = (accum[i + k + 1] - accum[i - k]) / (2 * k + 1);
        }
        return res;
    }
};
// @lc code=end
