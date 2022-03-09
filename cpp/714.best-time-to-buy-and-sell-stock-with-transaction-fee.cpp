/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int profit = 0;
        int cost = INT_MAX;
        for (auto p : prices)
        {
            if (p > cost)
            {
                profit += p - cost;
                cost = p;
            }
            else if (p + fee < cost)
            {
                cost = p + fee;
            }
        }
        return profit;
    }
};
// @lc code=end
