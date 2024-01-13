/*
 * @lc app=leetcode id=2397 lang=cpp
 *
 * [2397] Maximum Rows Covered by Columns
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int ans_0 = 0;
        vector<int> simpl_m;
        int n = matrix[0].size();
        for (auto &r : matrix)
        {
            int val = 0;
            for (int i = 0; i != n; ++i)
            {
                if (r[i])
                {
                    val |= 1 << i;
                }
            }
            if (val == 0)
            {
                ans_0 += 1;
            }
            else
            {
                if (__builtin_popcount(val) <= numSelect)
                {
                    simpl_m.push_back(val);
                }
            }
        }
        int ans = ans_0;
        for (int i = 1; i != (1 << n); ++i)
        {
            if (__builtin_popcount(i) != numSelect)
            {
                continue;
            }
            int cover = ans_0;
            for (auto s : simpl_m)
            {
                if ((s & i) == s)
                {
                    cover += 1;
                }
            }
            ans = max(ans, cover);
        }
        return ans;
    }
};
// @lc code=end
