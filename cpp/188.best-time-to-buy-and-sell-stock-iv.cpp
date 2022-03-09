/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
// t:O(kn), s:O(k)
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<int> prev_hold(k + 1, INT_MIN);
        vector<int> prev_unhold(k + 1, 0);
        int w = prices.size();
        for (int i = 0; i != w; ++i)
        {
            vector<int> next_prev_hold = prev_hold;
            for (int j = 1; j <= k; ++j)
            {
                next_prev_hold[j - 1] = max(next_prev_hold[j - 1], prev_unhold[j] - prices[i]);
            }
            vector<int> next_prev_unhold = prev_unhold;
            for (int j = 0; j <= k; ++j)
            {
                next_prev_unhold[j] = max(next_prev_unhold[j], prev_hold[j] + prices[i]);
            }
            prev_hold = move(next_prev_hold);
            prev_unhold = move(next_prev_unhold);
        }
        return *max_element(prev_unhold.begin(), prev_unhold.end());
    }
};
// @lc code=end
