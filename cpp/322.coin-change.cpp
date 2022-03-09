/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        int coins_len = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        int min_coin = INT_MAX;
        for (auto &n : coins)
        {
            if (n == amount)
            {
                return 1;
            }
            min_coin = min(min_coin, n);
        }
        if (min_coin > amount)
        {
            return -1;
        }
        dp[min_coin] = 1;
        for (int i = min_coin; i <= amount; ++i)
        {
            for (int j = 0; j < coins_len; ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
// @lc code=end

//TLE
// class Solution
// {
// public:
//     int coinChange(vector<int> &coins, int amount)
//     {
//         if (amount == 0)
//         {
//             return 0;
//         }
//         sort(coins.begin(), coins.end(), greater<int>());
//         int len = coins.size();
//         int start_index = len - (upper_bound(coins.rbegin(), coins.rend(), amount) - coins.rbegin());
//         if (start_index >= len)
//         {
//             return -1;
//         }
//         queue<int> left_coins, indexes;
//         left_coins.push(amount);
//         indexes.push(start_index);
//         int count = 0;
//         while (!left_coins.empty())
//         {
//             ++count;
//             int q_len = left_coins.size();
//             while (q_len--)
//             {
//                 auto current_amount = left_coins.front();
//                 auto current_index = indexes.front();
//                 left_coins.pop();
//                 indexes.pop();
//                 for (auto i = current_index; i != len; ++i)
//                 {
//                     if (current_amount > coins[i])
//                     {
//                         left_coins.push(current_amount - coins[i]);
//                         indexes.push(i);
//                     }
//                     else if (current_amount == coins[i])
//                     {
//                         return count;
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };