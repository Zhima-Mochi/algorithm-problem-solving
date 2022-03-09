/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        //return true;
        int len = piles.size();
        vector<int> dp = piles;
        for (int d = 1; d < len; ++d)
            for (int i = 0; i < len - d; ++i)
                dp[i] = max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
        return dp[0] > 0;
    }
};
// @lc code=end
