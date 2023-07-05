/*
 * @lc app=leetcode id=1959 lang=cpp
 *
 * [1959] Minimum Total Space Wasted With K Resizing Operations
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n^2*k), s:O(n*(n+k)
class Solution
{
public:
    int minSpaceWastedKResizing(vector<int> &nums, int k)
    {
        int w = nums.size();
        vector<vector<int>> max_size(w, vector<int>(w));
        vector<int> accum_sum(w + 1);
        for (int i = 0; i != w; ++i)
        {
            accum_sum[i + 1] = accum_sum[i] + nums[i];
            int mv = 0;
            for (int j = i; j != w; ++j)
            {
                mv = max(mv, nums[j]);
                max_size[i][j] = mv;
            }
        }
        vector<vector<int>> memo(w + 1, vector<int>(k + 2, -1));
        memo[0][0] = 0;
        for (int i = 0; i < w + 1; ++i)
        {
            for (int j = i + 1; j <= w; ++j)
            {
                for (int m = 0; m < k + 1; ++m)
                {
                    if (memo[i][m] == -1)
                    {
                        continue;
                    }
                    if (memo[j][m + 1] == -1)
                    {
                        memo[j][m + 1] = memo[i][m] + max_size[i][j - 1] * (j - i) - (accum_sum[j] - accum_sum[i]);
                    }
                    else
                    {
                        memo[j][m + 1] = min(memo[j][m + 1], memo[i][m] + max_size[i][j - 1] * (j - i) - (accum_sum[j] - accum_sum[i]));
                    }
                }
            }
        }
        return memo[w][k + 1];
    }
};
// @lc code=end
