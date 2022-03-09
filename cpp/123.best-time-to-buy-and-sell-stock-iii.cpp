/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
#include <vector>
using namespace std;
// @lc code=start
// T:O(N) S:O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int width = prices.size();
        int first_transaction_lowest_price = prices[0];
        int second_transaction_lowest_price = prices[0];
        int first_transaction_revenue = 0;
        int max_revenue = 0;
        for (auto i = 1; i != width; ++i)
        {
            if (prices[i] > first_transaction_lowest_price)
            {
                first_transaction_revenue = max(first_transaction_revenue, prices[i] - first_transaction_lowest_price);
            }
            else
            {
                first_transaction_lowest_price = prices[i];
            }
            if (prices[i] - first_transaction_revenue < second_transaction_lowest_price)
            {
                second_transaction_lowest_price = prices[i] - first_transaction_revenue;
            }
            else
            {
                max_revenue = max(max_revenue, prices[i] - second_transaction_lowest_price);
            }
        }
        return max_revenue;
    }
};
// @lc code=end
// T:O(N) S:O(N)
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int width = prices.size();
//         vector<int> dp(width);
//         int lowest_price = prices[0];
//         for (auto i = 1; i != width; ++i)
//         {
//             if (prices[i] > lowest_price)
//             {
//                 dp[i] = max(dp[i - 1], prices[i] - lowest_price);
//             }
//             else
//             {
//                 lowest_price = prices[i];
//                 dp[i] = dp[i - 1];
//             }
//         }
//         int max_revenue = dp[width - 1];
//         int highest_price = prices[width - 1];
//         for (auto i = width - 1; i != -1; --i)
//         {
//             if (prices[i] < highest_price)
//             {
//                 max_revenue = max(max_revenue, dp[i] + highest_price - prices[i]);
//             }
//             else
//             {
//                 highest_price = prices[i];
//             }
//         }
//         return max_revenue;
//     }
// };