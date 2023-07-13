/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(n^3), s:O(n^2);
class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
    {
        int w = stones.size();
        int res = 0;
        if ((w - 1) % (k - 1))
        {
            return -1;
        }
        vector<int> accum(w);
        vector<vector<int>> memo(w, vector<int>(w, INT_MAX - 1000));
        for (int i = 0; i != w; ++i)
        {
            if (i > 0)
            {
                accum[i] = accum[i - 1] + stones[i];
            }
            else
            {
                accum[i] = stones[i];
            }
            memo[i][i] = 0;
        }

        for (int i = 2; i <= w; ++i)
        {
            for (int l = 0; l != w && l + i - 1 != w; ++l)
            {
                int r = l + i - 1;
                for (int p = l; p < r; p += k - 1)
                {
                    memo[l][r] = min(memo[l][r], memo[l][p] + memo[p + 1][r]);
                }
                if ((r - l) % (k - 1) == 0)
                {
                    memo[l][r] += accum[r] - (l == 0 ? 0 : accum[l - 1]);
                }
            }
        }
        return memo[0][w - 1];
    }
};
// @lc code=end
