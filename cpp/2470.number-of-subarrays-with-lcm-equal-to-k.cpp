/*
 * @lc app=leetcode id=2470 lang=cpp
 *
 * [2470] Number of Subarrays With LCM Equal to K
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subarrayLCM(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i != n; ++i)
        {
            int cur = 1;
            for (int j = i; j != n; ++j)
            {
                if (k % nums[j] != 0)
                {
                    break;
                }
                cur = lcm(cur, nums[j]);
                if (cur == k)
                {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
