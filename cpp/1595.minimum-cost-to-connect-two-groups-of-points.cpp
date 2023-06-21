/*
 * @lc app=leetcode id=1595 lang=cpp
 *
 * [1595] Minimum Cost to Connect Two Groups of Points
 */
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int connectTwoGroups(vector<vector<int>> &cost)
    {
        int l = cost.size(), w = cost[0].size();
        int bit_w = 1 << w;
        vector<int> dp(bit_w, INT_MAX - 10000);
        vector<int> temp(bit_w);
        dp[0] = 0;
        for (int i = 1; i != l + 1; ++i)
        {
            for (int j = 0; j != bit_w; ++j)
            {
                temp[j] = INT_MAX - 10000;
                for (int k = 0; k != w; ++k)
                {
                    if ((j & (1 << k)) == 0)
                    {
                        continue;
                    }
                    temp[j] = min(temp[j], temp[j ^ (1 << k)] + cost[i - 1][k]);
                    temp[j] = min(temp[j], dp[j] + cost[i - 1][k]);
                    temp[j] = min(temp[j], dp[j ^ (1 << k)] + cost[i - 1][k]);
                }
            }
            dp.swap(temp);
        }
        return dp[bit_w - 1];
    }
};

// @lc code=end
