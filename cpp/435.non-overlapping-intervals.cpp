/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &l, vector<int> &r)
             { return l[1] < r[1]; });
        int count = 0;
        int endPt = INT32_MIN;
        for (auto &v : intervals)
        {
            if (v[0] >= endPt)
            {
                endPt = v[1];
                ++count;
            }
        }
        return intervals.size()-count;
    }
};
// @lc code=end
