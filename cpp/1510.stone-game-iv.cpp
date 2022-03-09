/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)

class Solution
{
    unordered_map<int, bool> dp;
public:
    bool winnerSquareGame(int n)
    {
        if (dp.count(n))
        {
            return dp[n];
        }
        for (int i = round(sqrt(n)); i != 0; --i)
        {
            if (i * i > n)
            {
                continue;
            }
            if (i * i == n)
            {
                return dp[n] = true;
            }
            else if (!winnerSquareGame(n - i * i))
            {
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
};

// @lc code=end
