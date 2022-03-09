/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](vector<int> &l, vector<int> &r)
             { return l[1] < r[1]; });
        int res = 1;
        auto min_right_side = points[0][1];
        int len = points.size();
        for (int i = 1; i != len; ++i)
        {
            if (points[i][0] > min_right_side)
            {
                ++res;
                min_right_side = points[i][1];
            }
        }
        return res;
    }
};
// @lc code=end
