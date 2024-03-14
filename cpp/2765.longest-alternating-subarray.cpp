/*
 * @lc app=leetcode id=2765 lang=cpp
 *
 * [2765] Longest Alternating Subarray
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int ans = 0;
        int prev1 = -2;
        int prev2 = -2;
        int cur = 0;
        for (auto num : nums)
        {
            if (cur >= 2)
            {
                if (num != prev2)
                {
                    if (num - prev1 == 1)
                    {
                        cur = 2;
                    }
                    else
                    {
                        cur = 1;
                    }
                }
                else
                {
                    cur += 1;
                }
            }
            else
            {
                if (num - prev1 == 1)
                {
                    cur = 2;
                }
                else
                {
                    cur = 1;
                }
            }
            prev2 = prev1;
            prev1 = num;
            ans = max(ans, cur);
        }
        return ans > 1 ? ans : -1;
    }
};
// @lc code=end
