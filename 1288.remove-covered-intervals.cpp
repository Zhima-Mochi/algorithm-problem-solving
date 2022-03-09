/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &l, vector<int> &r)
             { return l[0] < r[0] ? true : l[0] == r[0] ? l[1] > r[1]
                                                        : false; });
        int prev = 0;
        int res = 0;
        for (auto &v : intervals)
        {
            if (v[1] > prev)
            {
                res += 1;
                prev = v[1];
            }
        }
        return res;
    }
};
// @lc code=end
