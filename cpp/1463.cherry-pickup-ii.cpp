/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> dp(w, vector<int>(w));
        vector<vector<int>> next_dp(w, vector<int>(w));
        dp[0][w - 1] = grid[0][0] + grid[0][w - 1] + 1;
        for (int row = 1; row < h; ++row)
        {
            for (int bot_1_pos = 0; bot_1_pos != w; ++bot_1_pos)
            {
                for (int bot_2_pos = 0; bot_2_pos != w; ++bot_2_pos)
                {
                    if (dp[bot_1_pos][bot_2_pos] > 0)
                    {
                        for (int bot_1_move = -1; bot_1_move != 2; ++bot_1_move)
                        {
                            int bot_1_next_pos = bot_1_pos + bot_1_move;
                            if (bot_1_next_pos < 0 || bot_1_next_pos >= w)
                            {
                                continue;
                            }
                            for (int bot_2_move = -1; bot_2_move != 2; ++bot_2_move)
                            {
                                int bot_2_next_pos = bot_2_pos + bot_2_move;
                                if (bot_2_next_pos < 0 || bot_2_next_pos >= w)
                                {
                                    continue;
                                }
                                if (bot_1_next_pos != bot_2_next_pos)
                                {
                                    next_dp[bot_1_next_pos][bot_2_next_pos] = max(next_dp[bot_1_next_pos][bot_2_next_pos], dp[bot_1_pos][bot_2_pos] + grid[row][bot_1_next_pos] + grid[row][bot_2_next_pos]);
                                }
                                else
                                {
                                    next_dp[bot_1_next_pos][bot_2_next_pos] = max(next_dp[bot_1_next_pos][bot_2_next_pos], dp[bot_1_pos][bot_2_pos] + grid[row][bot_1_next_pos]);
                                }
                            }
                        }
                    }
                }
            }
            // notice that for any element in next_dp, is not less than the same place in dp
            // after swap, we do not need to reset any value to zero in next_dp
            swap(next_dp, dp);
        }
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                res = max(dp[i][j], res);
            }
        }
        return res - 1;
    }
};
// @lc code=end
