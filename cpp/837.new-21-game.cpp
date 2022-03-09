/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
// T:O(k+maxPts) S:O(maxPts)
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (n - k >= maxPts || k == 0)
        {
            return 1;
        }
        queue<double> dp;
        dp.push(1);
        double current = 1;
        for (int i = 1; i != k; ++i)
        {
            if (dp.size() == maxPts + 1)
            {
                current -= dp.front();
                dp.pop();
            }
            dp.push(current * 1 / maxPts);
            current += current * 1 / maxPts;
        }
        double res = 0;
        int sz = dp.size();
        while (sz)
        {
            res += dp.front() * min(n - k + 1, maxPts + 1 - sz--) / maxPts;
            dp.pop();
        }
        return res;
    }
};

// @lc code=end

// // T:O(min(k+maxPts, n)) S:O(k+maxPts)
// class Solution
// {
// public:
//     double new21Game(int n, int k, int maxPts)
//     {
//         if (n - k >= maxPts || k == 0)
//         {
//             return 1;
//         }
//         vector<double> dp(k + maxPts);
//         for (int i = k; i <= n && i < k + maxPts; ++i)
//         {
//             dp[i] = 1;
//         }
//         dp[k - 1] = static_cast<double>(min(n - k + 1, maxPts)) / maxPts;
//         for (int i = k - 2; i != -1; --i)
//         {
//             dp[i] = dp[i + 1] - (dp[i + maxPts + 1] - dp[i + 1]) / maxPts;
//         }
//         return dp[0];
//     }
// };