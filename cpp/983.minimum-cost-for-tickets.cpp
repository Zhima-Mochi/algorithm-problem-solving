/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start

// t:O(len(days)), s:O(len(days))
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int w = days.size();
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i != w; ++i)
        {
            dp[i + 1] = min(dp[i] + costs[0], dp[i + 1]);
            int idx_7 = lower_bound(days.begin() + i, days.end(), days[i] + 7) - days.begin();
            dp[idx_7] = min(dp[i] + costs[1], dp[idx_7]);
            int idx_30 = lower_bound(days.begin() + i, days.end(), days[i] + 30) - days.begin();
            dp[idx_30] = min(dp[i] + costs[2], dp[idx_30]);
        }
        return dp[w];
    }
};
// @lc code=end
