/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int w = satisfaction.size();
        vector<int> accum(w);
        accum[w - 1] = satisfaction[w - 1];
        int res = 0;
        int current = w * satisfaction[w - 1];
        for (int i = w - 2; i != -1; --i)
        {
            accum[i] = satisfaction[i] + accum[i + 1];
            current += (i + 1) * satisfaction[i];
        }
        for (int i = 0; i != w; ++i)
        {
            if (current > res)
            {
                res = current;
            }
            current -= accum[i];
        }
        return res;
    }
};
// @lc code=end
