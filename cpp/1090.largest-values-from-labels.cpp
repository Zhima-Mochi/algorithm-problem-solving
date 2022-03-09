/*
 * @lc app=leetcode id=1090 lang=cpp
 *
 * [1090] Largest Values From Labels
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        int w = values.size();
        vector<int> decreasing_ldx(w);
        iota(decreasing_ldx.begin(), decreasing_ldx.end(), 0);
        sort(decreasing_ldx.begin(), decreasing_ldx.end(), [&](int l, int r)
             { return values[l] > values[r]; });
        unordered_map<int, int> used;
        int res = 0;
        for (auto idx : decreasing_ldx)
        {
            if (numWanted == 0)
            {
                break;
            }
            if (++used[labels[idx]] <= useLimit)
            {
                res += values[idx];
                --numWanted;
            }
        }
        return res;
    }
};
// @lc code=end
