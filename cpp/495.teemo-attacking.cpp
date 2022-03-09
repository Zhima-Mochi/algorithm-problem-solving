/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */
#include <vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int len = timeSeries.size();
        if (len == 1)
        {
            return duration;
        }
        int res = duration;
        for (int i = 1; i != len; ++i)
        {
            res += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return res;
    }
};
// @lc code=end
