/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(len(stones)*sum), s:O(sum)
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum_val = accumulate(stones.begin(), stones.end(), 0);
        int half_sum = sum_val / 2;
        vector<bool> dp(half_sum + 1);
        dp[0] = true;
        for (auto stone : stones)
        {
            for (int i = half_sum - stone; i >= 0; --i)
            {
                if (dp[i])
                {
                    dp[i + stone] = true;
                }
            }
        }
        for (int i = half_sum; i >= 0; --i)
        {
            if (dp[i])
            {
                return sum_val - 2 * i;
            }
        }
        return sum_val;
    }
};
// @lc code=end
