/*
 * @lc app=leetcode id=1610 lang=cpp
 *
 * [1610] Maximum Number of Visible Points
 */
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// @lc code=start

//t: O(n*log(n)) s: O(n)
class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        if (angle == 360)
        {
            return points.size();
        }
        vector<double> points_angle;
        int origin_points = 0;
        for (auto &&point : points)
        {
            double x = point[0] - location[0];
            double y = point[1] - location[1];
            double point_angle;
            if (x == 0 && y == 0)
            {
                ++origin_points;
                continue;
            }

            if (x == 0)
            {
                if (y > 0)
                {
                    point_angle = 90;
                }
                else
                {
                    point_angle = 270;
                }
            }
            else if (x > 0)
            {
                if (y >= 0)
                {
                    point_angle = atan(y / x);
                }
                else
                {
                    point_angle = atan(y / x) + 2 * M_PI;
                }
                point_angle *= 360 / (2 * M_PI);
            }
            else
            {
                if (y >= 0)
                {
                    point_angle = atan(y / x) + M_PI;
                }
                else
                {
                    point_angle = M_PI + atan(y / x);
                }
                point_angle *= 360 / (2 * M_PI);
            }

            points_angle.push_back(point_angle);
        }

        sort(points_angle.begin(), points_angle.end());

        for (int i = 0, width = points_angle.size(); i != width && points_angle[i] <= angle; ++i)
        {
            points_angle.push_back(360 + points_angle[i]);
        }
        int ind = 0;
        int tail = 0;
        int width = points_angle.size();

        int res = 0;
        while (ind != width && points_angle[ind] < 360)
        {
            double upper_bound_angle = points_angle[ind] + angle;
            int next_tail = upper_bound(points_angle.begin() + tail, points_angle.end(), upper_bound_angle) - points_angle.begin();
            tail = next_tail;
            res = max(res, (tail - ind));
            while (ind + 1 != width && points_angle[ind + 1] == points_angle[ind])
            {
                ++ind;
            }
            ++ind;
        }
        return res + origin_points;
    }
};
// @lc code=end
