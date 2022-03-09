/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int width = prices.size();
        int cooldownRevenue = 0;
        int nonCooldownRevenue = 0;
        for (int i = 1; i != width; ++i)
        {
            auto next_cooldownRevenue = max(cooldownRevenue, nonCooldownRevenue);
            nonCooldownRevenue = max({cooldownRevenue, nonCooldownRevenue + prices[i] - prices[i - 1]});
            cooldownRevenue = next_cooldownRevenue;
        }
        return max(cooldownRevenue, nonCooldownRevenue);
    }
};
// @lc code=end
