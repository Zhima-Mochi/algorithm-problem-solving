/*
 * @lc app=leetcode id=1779 lang=cpp
 *
 * [1779] Find Nearest Point That Has the Same X or Y Coordinate
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int res = -1;
        int smallest_dist = INT_MAX;
        for (int i = 0, width = points.size(); i != width; ++i)
        {
            int dist;
            if (x == points[i][0])
            {
                dist = abs(points[i][1] - y);
            }
            else if (y == points[i][1])
            {
                dist = abs(points[i][0] - x);
            }
            else
            {
                continue;
            }
            if (dist < smallest_dist)
            {
                smallest_dist = dist;
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end
