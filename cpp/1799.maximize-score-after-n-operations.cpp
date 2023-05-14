/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 */
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        int w = nums.size();
        int n = w / 2;
        vector<int> records(1 << w);
        vector<vector<int>> gcds(w, vector<int>(w));
        function<int(int, int)> pos_gcd = [&](int i, int j) -> int
        {
            if (gcds[i][j] != 0)
            {
                return gcds[i][j];
            }
            if (i == j)
            {
                return gcds[i][j] = nums[i];
            }
            return gcds[i][j] = gcd(nums[i], nums[j]);
        };
        function<int(int)> dp = [&](int mask) -> int
        {
            int i = __builtin_popcount(mask) / 2 + 1;
            if (i == w)
            {
                return 0;
            }
            if (records[mask] != 0)
            {
                return records[mask];
            }
            for (int j = 0; j < w; j++)
            {
                if ((mask & (1 << j)) == 0)
                {
                    for (int k = j + 1; k < w; k++)
                    {
                        if ((mask & (1 << k)) == 0)
                        {
                            records[mask] = max(records[mask], i * pos_gcd(j, k) + dp(mask | (1 << j) | (1 << k)));
                        }
                    }
                }
            }
            return records[mask];
        };
        return dp(0);
    }
};
// @lc code=end
