/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int w = tops.size();
        vector<vector<int>> dp = {{0, 1}, {0, 1}};
        for (int i = 1; i != w; ++i)
        {
            if (dp[0].empty())
            {
            }
            else if (tops[i] == tops[0] && bottoms[i] != tops[0])
            {
                dp[0][1] += 1;
            }
            else if (bottoms[i] == tops[0] && tops[i] != tops[0])
            {
                dp[0][0] += 1;
            }
            else if (tops[i] != tops[0] && bottoms[i] != tops[0])
            {
                dp[0] = vector<int>();
            }
            if (dp[1].empty())
            {
            }
            else if (bottoms[i] == bottoms[0] && tops[i] != bottoms[0])
            {
                dp[1][1] += 1;
            }
            else if (tops[i] == bottoms[0] && bottoms[i] != bottoms[0])
            {
                dp[1][0] += 1;
            }
            else if (bottoms[i] != bottoms[0] && tops[i] != bottoms[0])
            {
                dp[1] = vector<int>();
            }
            if (dp[0].empty() && dp[1].empty())
            {
                return -1;
            }
        }
        return min(!dp[0].empty() ? min(dp[0][0], dp[0][1]) : w, !dp[1].empty() ? min(dp[1][0], dp[1][1]) : w);
    }
};
// @lc code=end
